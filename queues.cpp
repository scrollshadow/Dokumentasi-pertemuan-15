/**
 * @mainpage Documentation Circular Queues
 *
 * @section Introduction
 * Project ini merupakan project struktur data
 * menggunakan struktur data queues dengan pendekatan circular arrays.
 *
 * @section Operations
 * Project ini memiliki beberapa operasi antara lain:
 * 1. Insert
 * 2. Delete
 * 3. Display
 *
 * @section Cara Penggunaan
 * Berikut beberapa menu yang bisa digunakan:
 * 1. en queue
 * 2. de queue
 * 3. display
 * 4. exit
 *
 * @author Profil
 * - nama  : Gusty Try Zaldhy Pramana
 * - nim   : 20250140156
 * - kelas : D
 *
 * @brief
 * @version 0.1
 * @date 2026-06-08
 *
 * @copyright gusty.try.ft25@mail.umy.ac.id (c) 2026
 *
 */



#include <iostream>
using namespace std;
/**
 * @class Queues
 * @brief class ini untuk operasi lengkap queues
 *
 *
 */
class Queues {
private:
    int FRONT;          ///< variable private front untuk menyimpan posisi depan antrian
    int REAR;           ///< variable private rear untuk menyimpan posisi belakang antrian
    int max = 5;        ///< variable private max untuk menyimpan ukuran maximum antrian
    int queue_array[5]; ///< variable private queue_array untuk menyimpan elemen antrian

public:
    /**
     * @brief Construct a new Queues object
     * set default queues null
     * with front = -1 and rear = -1
     */
    Queues() {
        FRONT = -1;
        REAR = -1;
    }

    /**
     * @brief method untuk memasukkan data dalam antrian
     * data dimasukkan dalam variable queue_array
     */
    void insert() {
        int num; ///< variable num untuk menyimpan nilai
        cout << "Enter a number: ";
        cin  >> num;
        cout << endl;

        // Cek apakah antrian penuh
        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)) {
            cout << "\nQueue overflow\n";
            return;
        }

        // Jika antrian kosong
        else if (FRONT == -1) {
            FRONT = 0;
            REAR  = 0;
            queue_array[REAR] = num;
        }

        // Jika REAR sudah di ujung, wrap around ke awal (circular)
        else if (REAR == max - 1) {
            REAR = 0;
            queue_array[REAR] = num;
        }

        // Kondisi normal
        else {
            REAR++;
            queue_array[REAR] = num;
        }

        cout << "Inserted: " << num << endl;
    }

    /**
     * @brief method untuk menghapus data dari antrian
     * data dihapus dari posisi FRONT
     */
    void remove() {
        // cek apakah antrian kosong
        if (FRONT == -1) {
            cout << "\nQueue underflow\n";
            return;
        }

        cout << "Deleted element: " << queue_array[FRONT] << endl;

        // Jika hanya ada 1 elemen
        if (FRONT == REAR) {
            FRONT = -1;
            REAR  = -1;
        }

        // Wrap around ke awal jika FRONT di ujung
        else if (FRONT == max - 1) {
            FRONT = 0;
        }

        else {
            FRONT++;
        }
    }

    /**
     * @brief method untuk menampilkan semua elemen antrian
     * menampilkan isi queue_array dari FRONT sampai REAR
     */
     void display()
    {
        int FRONT_Position = FRONT; //<Vairable untuk menandakan posisi element pertama pada variable front
        int REAR_Position = REAR;//<Variable untuk menandakan posisi element terakhir pada variiable rear

        //cek antrian kosong
        if (FRONT_Position == -1)
        {
            cout << "Queue is empty\n";
            return;
        }
        
        cout << "\nElement is the queue are. . . .\n";

        //jika FRONT <= REAR, iterasi dari FRONT hingga REAR
        if (FRONT_Position <= REAR_Position)
        {
            while (FRONT_Position <= REAR_Position)
            {
                cout << queue_array[FRONT_Position] << "  ";
                FRONT_Position++;
            }
            cout << endl;
            
        }
        else
        {
            //jika front <= rear, iterasi dari front hingga akhir array
            while (FRONT_Position <= max -1)
            {
                cout << queue_array[FRONT_Position] << "  ";
                FRONT_Position++;
            }
            cout << endl;
            
        }

    }

};

/**
 * @brief Main function - menu utama program
 * @return int
 */
int main()
{
    Queues q;///<objeck untuk menggunakan member pada class queues
    char ch;///<variabel ch untuk menyimpan pilihan pada menu yg diberikan

    while (true)
    {
        try
        {
            cout << "Menu" << endl;
            cout << "1. Implement Insert operation" << endl;
            cout << "2. Implement Delete Operation" << endl;
            cout << "3. Display values" << endl;
            cout << "4. Exit" << endl;

            cout << "\nEnter your choice (1-4): ";
            cin >> ch;
            cout << endl;

            switch (ch)
            {
            case '1':
                q.insert();
                break;

            case '2':
                q.remove();
                break;

            case '3':
                q.display();
                break;

            case '4':
                return 0;

            default:
                cout << "Invalid option!!" << endl;
                break;
            }
        }

        catch (exception &ex)
        {
            cout << "Check for the values entered!!" << endl;
        }
    }

    return 0;
}