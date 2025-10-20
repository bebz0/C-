#include <iostream>

using namespace std;

double calculateMean(const double *data, int size)
{
    if (size == 0)
    {
        return 0.0;
    }

    double sum = 0.0;
    for (int i = 0; i < size; i++)
    {
        sum += data[i];
    }

    return sum / size;
}

double calculateVariance(const double *data, int size)
{
    if (size < 2)
    {
        return 0.0;
    }

    double mean = calculateMean(data, size);
    double sumOfSquares = 0.0;

    // Sum the squared differences from the mean
    for (int i = 0; i < size; i++)
    {
        double difference = data[i] - mean;
        sumOfSquares += difference * difference;
    }

    return sumOfSquares / size;
}

void processDataEntry(double **values_ptr, int &size_ref)
{
    int count;
    cout << "\nHow many new values doyou want to enter? ";
    cin >> count;

    if (count <= 0)
    {
        cout << "Count must be a positive number." << endl;
        return;
    }

    int newSize = size_ref + count;
    double *newArray = new double[newSize];

    for (int i = 0; i < size_ref; i++)
    {
        newArray[i] = (*values_ptr)[i];
    }

    cout << "Enter " << count << " real numbers:" << endl;
    for (int i = 0; i < count; i++)
    {
        double value;
        cout << i + 1 << ": ";
        cin >> value;
        newArray[size_ref + i] = value;
    }

    delete[] *values_ptr;

    *values_ptr = newArray;
    size_ref = newSize;

    cout << "\nCurrent Statistics" << endl;
    cout << "Total values: " << size_ref << endl;
    cout << "Mean: " << calculateMean(*values_ptr, size_ref) << endl;
    cout << "Variance: " << calculateVariance(*values_ptr, size_ref) << endl;
}

int main()
{
    double *values = nullptr;
    int size = 0;
    char userChoice;

    while (true)
    {
        processDataEntry(&values, size);

        cout << "Continue entering values? (y/n): ";

        cin >> userChoice;

        if (userChoice != 'y')
        {
            break;
        }
    }

    delete[] values;

    return 0;
}