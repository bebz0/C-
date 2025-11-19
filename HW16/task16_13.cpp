#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>

using namespace std;

const int MAX_PRODUCTS = 100;
const char *FILENAME = "products.bin";

void writeStr(ofstream &ofs, const string &str)
{
    size_t len = str.length();
    ofs.write((char *)&len, sizeof(len));
    ofs.write(str.c_str(), len);
}

string readStr(ifstream &ifs)
{
    size_t len;
    if (!ifs.read((char *)&len, sizeof(len)))
        return "";
    string str(len, '\0');
    ifs.read(&str[0], len);
    return str;
}

time_t parseDate(const string &s)
{
    tm t = {0};
    char d;
    stringstream ss(s);
    ss >> t.tm_year >> d >> t.tm_mon >> d >> t.tm_mday;
    t.tm_year -= 1900;
    t.tm_mon -= 1;
    return mktime(&t);
}

string formatDate(time_t t)
{
    char buf[16];
    strftime(buf, 16, "%Y-%m-%d", localtime(&t));
    return string(buf);
}

enum class Type
{
    Toy = 1,
    Food,
    Appliance
};

class Product
{
protected:
    string name, sku, unit;
    double price;
    time_t delivery;

public:
    Product(string n = "", string s = "", string u = "", double p = 0, string d = "1970-01-01")
        : name(n), sku(s), unit(u), price(p), delivery(parseDate(d)) {}
    virtual ~Product() = default;
    virtual Type getType() const = 0;
    string getName() const { return name; }
    double getPrice() const { return price; }

    virtual void show() const
    {
        cout << "Name: " << name << " (SKU: " << sku << ")\n"
             << "Price: " << price << " per " << unit << "\n"
             << "Delivery: " << formatDate(delivery) << endl;
    }
    virtual void save(ofstream &ofs) const
    {
        writeStr(ofs, name);
        writeStr(ofs, sku);
        writeStr(ofs, unit);
        ofs.write((char *)&price, sizeof(price));
        ofs.write((char *)&delivery, sizeof(delivery));
    }
    virtual void load(ifstream &ifs)
    {
        name = readStr(ifs);
        sku = readStr(ifs);
        unit = readStr(ifs);
        ifs.read((char *)&price, sizeof(price));
        ifs.read((char *)&delivery, sizeof(delivery));
    }
    virtual void checkDiscount(time_t now) {}
};

class Toy : public Product
{
    int age;

public:
    Toy(string n = "", string s = "", string u = "", double p = 0, string d = "", int a = 0)
        : Product(n, s, u, p, d), age(a) {}
    Type getType() const override { return Type::Toy; }
    void show() const override
    {
        cout << "--- TOY ---\n";
        Product::show();
        cout << "Age: " << age << "+" << endl;
    }
    void save(ofstream &ofs) const override
    {
        Product::save(ofs);
        ofs.write((char *)&age, sizeof(age));
    }
    void load(ifstream &ifs) override
    {
        Product::load(ifs);
        ifs.read((char *)&age, sizeof(age));
    }
};

class Food : public Product
{
    time_t expiry;

public:
    Food(string n = "", string s = "", string u = "", double p = 0, string d = "", string ex = "")
        : Product(n, s, u, p, d), expiry(parseDate(ex)) {}
    Type getType() const override { return Type::Food; }
    void show() const override
    {
        cout << "--- FOOD ---\n";
        Product::show();
        cout << "Expiry: " << formatDate(expiry) << endl;
    }
    void save(ofstream &ofs) const override
    {
        Product::save(ofs);
        ofs.write((char *)&expiry, sizeof(expiry));
    }
    void load(ifstream &ifs) override
    {
        Product::load(ifs);
        ifs.read((char *)&expiry, sizeof(expiry));
    }
    void checkDiscount(time_t now) override
    {
        double diff = difftime(expiry, now);
        if (diff > 0 && diff < 5 * 86400)
        {
            price *= 0.8;
            cout << "Discount applied to " << name << ". New price: " << price << endl;
        }
    }
};

class Appliance : public Product
{
    bool warranty;
    int w_days;

public:
    Appliance(string n = "", string s = "", string u = "", double p = 0, string d = "", bool w = false, int wd = 0)
        : Product(n, s, u, p, d), warranty(w), w_days(wd) {}
    Type getType() const override { return Type::Appliance; }
    void show() const override
    {
        cout << "--- APPLIANCE ---\n";
        Product::show();
        cout << "Warranty: " << (warranty ? "Yes (" + to_string(w_days) + " days)" : "None") << endl;
    }
    void save(ofstream &ofs) const override
    {
        Product::save(ofs);
        ofs.write((char *)&warranty, sizeof(warranty));
        ofs.write((char *)&w_days, sizeof(w_days));
    }
    void load(ifstream &ifs) override
    {
        Product::load(ifs);
        ifs.read((char *)&warranty, sizeof(warranty));
        ifs.read((char *)&w_days, sizeof(w_days));
    }
    void checkDiscount(time_t now) override
    {
        if (!warranty)
            return;
        tm t = *localtime(&delivery);
        t.tm_mday += w_days;
        double diff = difftime(mktime(&t), now);
        if (diff > 0 && diff < 5 * 86400)
        {
            price *= 0.8;
            cout << "Discount applied to " << name << ". New price: " << price << endl;
        }
    }
};

class Warehouse
{
    Product *products[MAX_PRODUCTS];
    int count;

    Product *create(Type t)
    {
        switch (t)
        {
        case Type::Toy:
            return new Toy();
        case Type::Food:
            return new Food();
        case Type::Appliance:
            return new Appliance();
        default:
            return nullptr;
        }
    }

public:
    Warehouse() : count(0)
    {
        for (int i = 0; i < MAX_PRODUCTS; ++i)
            products[i] = nullptr;
        ifstream ifs(FILENAME, ios::binary);
        if (!ifs)
            return;
        while (ifs.peek() != EOF && count < MAX_PRODUCTS)
        {
            Type t;
            if (!ifs.read((char *)&t, sizeof(t)))
                break;
            if (Product *p = create(t))
            {
                p->load(ifs);
                products[count++] = p;
            }
        }
        cout << "Loaded " << count << " items.\n";
    }

    ~Warehouse()
    {
        ofstream ofs(FILENAME, ios::binary | ios::trunc);
        for (int i = 0; i < count; ++i)
        {
            Type t = products[i]->getType();
            ofs.write((char *)&t, sizeof(t));
            products[i]->save(ofs);
            delete products[i];
        }
        cout << "Saved and cleaned up.\n";
    }

    void add(Product *p)
    {
        if (count < MAX_PRODUCTS)
            products[count++] = p;
        else
        {
            cout << "Full!\n";
            delete p;
        }
    }

    void showAll()
    {
        if (count == 0)
            cout << "Empty.\n";
        for (int i = 0; i < count; ++i)
        {
            products[i]->show();
            cout << "--------------------\n";
        }
    }

    void search()
    {
        int opt;
        cout << "1. Name\n2. Type\nChoice: ";
        cin >> opt;
        cin.ignore();
        int found = 0;
        if (opt == 1)
        {
            string n;
            cout << "Name: ";
            getline(cin, n);
            for (int i = 0; i < count; ++i)
            {
                if (products[i]->getName().find(n) != string::npos)
                {
                    products[i]->show();
                    found++;
                }
            }
        }
        else
        {
            int t;
            cout << "Type (1-Toy, 2-Food, 3-Appliance): ";
            cin >> t;
            for (int i = 0; i < count; ++i)
            {
                if ((int)products[i]->getType() == t)
                {
                    products[i]->show();
                    found++;
                }
            }
        }
        if (!found)
            cout << "Not found.\n";
    }

    void order()
    {
        string n;
        double total = 0;
        while (true)
        {
            cout << "Add product (or 'done'): ";
            getline(cin, n);
            if (n == "done")
                break;
            bool found = false;
            for (int i = 0; i < count; ++i)
            {
                if (products[i]->getName() == n)
                {
                    total += products[i]->getPrice();
                    cout << "Added: " << n << " (" << products[i]->getPrice() << ")\n";
                    delete products[i];
                    for (int j = i; j < count - 1; ++j)
                        products[j] = products[j + 1];
                    products[--count] = nullptr;
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Not in stock.\n";
        }
        cout << "TOTAL: " << total << "\nOrder processed.\n";
    }

    void discounts()
    {
        time_t now = time(nullptr);
        for (int i = 0; i < count; ++i)
            products[i]->checkDiscount(now);
    }
};

int main()
{
    Warehouse wh;
    time_t now = time(nullptr);
    char buf[16];

    tm t = *localtime(&now);
    t.tm_mday += 3;
    strftime(buf, 16, "%Y-%m-%d", &t);
    string near = buf;
    t = *localtime(&now);
    t.tm_mday -= 15;
    strftime(buf, 16, "%Y-%m-%d", &t);
    string old = buf;

    wh.add(new Toy("Puzzle 'Burokratia'", "HARD-LVL", "box", 300.0, "2023-01-01", 18));
    wh.add(new Food("Shaurma 'Riskova'", "DANGER-X", "st", 85.0, "2025-01-01", "2025-12-31"));
    wh.add(new Appliance("Skarbnychka 'Hope'", "NOMONEY", "st", 200.0, "2024-01-01", true, 3650));
    wh.add(new Food("Bilyash 'Vokzalniy'", "DANGER-2", "pcs", 25.0, "2025-01-01", near));
    wh.add(new Appliance("Budylnik 'Infarct'", "SCREAM-1", "pcs", 450.0, "2024-01-01", true, 365));
    int c;
    do
    {
        cout << "\n1. Show\n2. Search\n3. Order\n4. Discounts\n0. Exit\n> ";
        cin >> c;
        cin.ignore();
        switch (c)
        {
        case 1:
            wh.showAll();
            break;
        case 2:
            wh.search();
            break;
        case 3:
            wh.order();
            break;
        case 4:
            wh.discounts();
            break;
        }
    } while (c != 0);
    return 0;
}