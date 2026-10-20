#include <iostream>
using namespace std;

int BinarySearchIterative(int data[], int n, int target) // fungsi untuk mencari posisi indeks dari target
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (data[mid] == target)
        {
            return mid;
        }
        else if (target < data[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1;
}

void urutkanData(int data[], int n) // fungsi untuk mengurutkan data 
{
    for (int i = 0; i < n - 1; i++)
    {
        bool berubah = false;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (data[j] > data[j + 1])
            {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;

                berubah = true;
            }
        }
        if (!berubah)
        {
            break;
        }
    }
}

int main()
{
    system ("cls");
    int data[30];
    int n = 0;
    int nilai = 0;
    int target;

    while (n < 30)
    {
        cout << "Masukkan nilai (-1 untuk berhenti) : ";
        cin >> nilai;

        if (nilai == -1)
        {
            if (n == 0) //untuk antisipasi user masukkan -1 di awal (data masih 0)
            {
                cout << "Peringatan: Data tidak boleh kosong! Masukkan minimal satu nilai awal." << endl;
                continue;
            }
            break;
        }

        data[n] = nilai;
        n++;
    }

    cout << endl;

    urutkanData(data, n);

    cout << "Data : ";
    for (int i = 0; i < n; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;

    cout << "Nilai yg dicari : ";
    cin >> target;

    int hasil = BinarySearchIterative(data, n, target);

    if (hasil != -1)
    {
        cout << "Data ditemukan pada indeks : " << hasil << endl;
    }
    else
    {
        cout << "Data tidak ditemukan" << endl;
    }

    return 0;
}
