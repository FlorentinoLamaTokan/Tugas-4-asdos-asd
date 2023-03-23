
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 5

int pilih;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct Tumpukan {
    char data[5][50];
    int top; 

}tumpuk;

struct Antrian {
    int head;
    int tail;
    int data[MAX];
}antrian;


void panah(int rp, int ap) {
    if (rp == ap) {
        printf("==>");
    }
    else {
        printf("   ");
    }
}

 int Queuekosong()
    {
        if(antrian.tail == -1)
        {
            return 1;
        }else{
            return 0;
        }
    }

 int QueuePenuh()
 {
     if (antrian.tail == MAX)
     {
         return 1;
     }
     else {
         return 0;
     }
 }


 void Queueinisialisasi()
 {
     antrian.head = antrian.tail = -1;
 }

 void enqueue()
 {
     int data;

     if (QueuePenuh()) {
         printf("antrian penuh");
         return;
     }
        

     if (Queuekosong())
         antrian.head = antrian.tail = 0;

     printf("masukkan data : ");
     scanf("%d", &data);
     antrian.data[antrian.tail] = data;
     printf("Data %d berhasil diinput!\n", antrian.data[antrian.tail]);
     
     if (!QueuePenuh())
         antrian.tail++;
 }

 int dequeue()
 {
     if (Queuekosong())
     {
         printf("Data masih kosong!\n");
     }
     else 
     {
         printf("data %d telah dikeluarkan dari antrian\n", antrian.data[antrian.head]);
         for (int i = antrian.head; i < antrian.tail; i++)
         {
             //printf("%d >> %d\n", antrian.data[i], antrian.data[i + 1]);
             antrian.data[i] = antrian.data[i + 1];
         }
         antrian.tail--;
         return antrian.data[antrian.head];

     }
     return 1;
 }


 void clear()
 {
     antrian.head = antrian.tail = -1;
     printf("Data telah di reset!\n");
 }

 void print()
 {
     if (Queuekosong())
     {
         printf("Data masih kosongg!");
         return;
     }

     printf("data yang telah diinput :\n");
     for (int i = 0; i < antrian.tail; i++)
         printf("%d. %d\n", i + 1, antrian.data[i]);
 }

 int MenuQueue()
 {
     printf("1.Enqueue\n");
     printf("2.Dequeue\n");
     printf("3.Print Queue\n");
     printf("4.Clear Queue\n");
     printf("5.Exit\n");
     printf("Input pilihan:");
     scanf("%d", &pilih);
     return pilih;
 }
 void Queue()
 {
     Queueinisialisasi();
     int pilihan = MenuQueue();
     
     while (pilihan) 
     {
         switch (pilih)
         {
         case 1:
             system("cls");
             enqueue();
             break;
         case 2:
             system("cls");
             dequeue();
             break;
         case 3:
             system("cls");
             print();
             break;
         case 4:
             system("cls");
             clear();
             break;
         case 5:
             system("cls");
             return;


         }
         if (pilih < 1 || pilih >5) {
             system("cls");
             printf("tidak ada pilihan menu, silahkan pilih menu lain!!");
         }
         _getch();
         system("cls");
         pilihan = MenuQueue();
     }
 }


int Stackkosong()
{
    if (tumpuk.top == 0)
    {
        return 1;
    }
    else {
        return 0;
    }
}


int Stackpenuh()
{
    if (tumpuk.top == MAX)
    {
        return 1;
    }
    else {
        return 0;
    }
}


void Stackinisialisasi()
{
    tumpuk.top = 0;
}


void push()
{
    char* temp[30];
    if (Stackpenuh()) 
    {
        printf("Data sudah penuh");
        return;
    }

    printf("Masukkan data:");
    scanf("%s", &temp);
    strcpy(tumpuk.data[tumpuk.top], temp);
    printf("Data %s berhasil di input\n", tumpuk.data[tumpuk.top]);
    tumpuk.top++;
}

void pop()
{
    if (Stackkosong())
    {
        printf("Data masih kosong\n");
        return;
    }
    printf("Data %s telah dibuang\n", tumpuk.data[tumpuk.top-1]);
    tumpuk.top--;
}

void printData()
{
    if (Stackkosong())
    {
        printf("Data masih kosong\n");
        return;
    }

    for (int i = tumpuk.top-1; i >= 0; i--)
    {
        printf("%s\n", tumpuk.data[i]);
    }
    
}

int MenuStack()
{
    printf("1.Push Stack\n");
    printf("2.Pop Stack\n");
    printf("3.Print Stack\n");
    printf("4.Clear Stack\n");
    printf("5.Exit\n");
    printf("Input pilihan:");
    scanf("%d", &pilih);
    return pilih;
}



void Stack()
{
    Stackinisialisasi();
    int pilihan = MenuStack();

    while (pilihan) 
    {
        switch (pilih)
        {
        case 1:
            system("cls");
            push();
            break;
        case 2:
            system("cls");
            pop();
            break;
        case 3:
            system("cls");
            printData();
            break;
        case 4:
            system("cls");
            if (Stackkosong)
            {
                printf("Data masih kosong!,tidak bisa reset\n");
            }
            else {
                Stackinisialisasi();
                printf("Data telah di reset!\n");
            }

            break;
        case 5:
            return;
        }

        if (pilih < 1 || pilih >5) 
        {
            system("cls");
            printf("tidak ada pilihan menu, silahkan pilih menu lain!!");
        }

        _getch();
        system("cls");
        pilihan = MenuStack();
    }

} 
    

int mainMenu()
{
    system("cls");
    system("COLOR F2");
    gotoxy(2, 2);
    printf("================");
    gotoxy(2, 3);
    printf("     WELCOME    ");
    gotoxy(2, 4);
    printf("================");
    gotoxy(2, 8);
    printf("================");
    int posisi = 1;
    int tekan = 0;

    while (tekan != 13) {
        gotoxy(2, 5);
        panah(1, posisi); printf(" 1. Stack String");
        gotoxy(2, 6);
        panah(2, posisi); printf(" 2. Queue Integer");
        gotoxy(2, 7);
        panah(3, posisi); printf(" 3. EXIT");
        tekan = _getch();
        if (tekan == 80 && posisi != 3) {
            posisi++;
        }
        else if (tekan == 72 && posisi != 1) {
            posisi--;
        }
        else {
            posisi = posisi;
        }
    }
    return posisi;

}

int main()
{
    int pilihan = mainMenu();

    while (pilihan)
    {
        switch (pilihan) {
        case 1:
            system("cls");
            system("COLOR F8");
            Stack();
            break;

        case 2:
            system("cls");
            system("COLOR F8");
            Queue();
            break;

        default:
            break;
        }
        system("cls");
        pilihan = mainMenu();
    }
    
}
