#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

void main_menu();
void user_menu();
void admin_menu();
void buy_menu();

template <typename T>
T get_input(const string &strQuery);

int indeksLagu=0;

struct data_profile
{
    string fullName;
    string address;
    string mobileNumber;
};
data_profile profile;

struct data_song
{
    char artist[50];
    char title[50];
    char genre[20];
    int price;
    int stock;
    int year;
};
data_song song[5000];

int buyIndex = 0;
int buyCart[50];
int totalItems[50];

bool acompare(data_song lhs, data_song rhs)
{
    return lhs.stock < rhs.stock;
}

void importLagu()
{
    string fileData;
    cout << "Enter the name of file you want to import : ";
    cin >> fileData;
    ifstream dataLagu(fileData);
    if (!dataLagu.is_open())
    {
        cout << "Failed opening file, make sure you enter the correct file name.\n\n";
        system("pause");
        importLagu();
    }

    while (dataLagu >> song[indeksLagu].artist >> song[indeksLagu].title >> song[indeksLagu].genre >> song[indeksLagu].price >> song[indeksLagu].stock >> song[indeksLagu].year)
    {
        indeksLagu++;
    }
    cout << "\n\nData Imported Successfully!\n\n";
    system("pause");
    admin_menu();
}
void inputLagu()
{
    int batas;
    cout << "How many data you want to input? : ";
    cin >> batas;
    for (int i = 0; i < batas; i++)
    {
        cin.ignore(256,'\n');
        cout << "Data-" << i+1 << endl;
        cout << "Artist Name :\t";
        cin.getline(song[indeksLagu].artist,50);
        cout << "Album Title :\t";
        cin.getline(song[indeksLagu].title,50);
        cout << "Genre :\t";
        cin.getline(song[indeksLagu].genre,20);
        cout << "Year :\t";
        cin >> song[indeksLagu].year;
        cout << "Price :\t";
        cin >> song[indeksLagu].price;
        cout << "Stock :\t";
        cin >> song[indeksLagu].stock;

        indeksLagu++;
    }
    cout << "\n\nData Inputed Successfully!\n\n";
    system("pause");
    admin_menu();
}

void bestSeller()
{
    system("cls");
    cout << "\tBEST SELLER ALBUM THIS MONTH!\n\n";

    sort(song,song+indeksLagu, acompare);

    cout << "Artist" << "\t\tAlbums" << "\t\tGenre" << "\t\tYear" << "\t\tPrice" << "\t\tStock\n\n";
    for (int i = 0; i < 5; i++)
    {
        cout << song[i].artist
        << "\t\t" << song[i].title
        << "\t\t" << song[i].genre
        << "\t\t" << song[i].year
        << "\t\t" << song[i].price
        << "\t\t" << song[i].stock
        << endl;
    }

    cout << "\n\n\n\tALBUM OF THE DAY!\n\n";
    cout << "Artist" << "\t\tAlbums" << "\t\tGenre" << "\t\tYear" << "\t\tPrice" << "\t\tStock\n\n";
    cout << song[0].artist
    << "\t\t" << song[0].title
    << "\t\t" << song[0].genre
    << "\t\t" << song[0].year
    << "\t\t" << song[0].price
    << "\t\t" << song[0].stock
    << endl << endl;
    system("pause");
    system("cls");
    user_menu();
}

void searchArtist(char key[])
{
    for (int i = 0; i < indeksLagu; i++)
    {
        if (strstr(song[i].artist,key))
        {
            cout << "No.\tArtist\t\tAlbum Title\t\tGenre\t\tYear\t\tPrice\t\tStock";
            cout << endl
            << i+1 << "\t"
            << song[i].artist
            << "\t\t"
            << song[i].title
            << "\t\t"
            << song[i].genre
            << "\t\t"
            << song[i].year
            << "\t\t"
            << song[i].price
            << "\t\t"
            << song[i].stock;
            cout << endl << endl;
        }
    }
}

void searchAlbum(char key[])
{
    for (int i = 0; i < indeksLagu; i++)
    {
        if (strstr(song[i].title,key))
        {
            cout << "No.\tArtist\t\tAlbum Title\t\tGenre\t\tYear\t\tPrice\t\tStock";
            cout << endl
            << i+1 << "\t"
            << song[i].artist
            << "\t\t"
            << song[i].title
            << "\t\t"
            << song[i].genre
            << "\t\t"
            << song[i].year
            << "\t\t"
            << song[i].price
            << "\t\t"
            << song[i].stock;
            cout << endl << endl;
        }
    }
}

void searchGenre(char key[])
{
    for (int i = 0; i < indeksLagu; i++)
    {
        if (strstr(song[i].genre,key))
        {
            cout << "No.\tArtist\t\tAlbum Title\t\tGenre\t\tYear\t\tPrice\t\tStock";
            cout << endl
            << i+1 << "\t"
            << song[i].artist
            << "\t\t"
            << song[i].title
            << "\t\t"
            << song[i].genre
            << "\t\t"
            << song[i].year
            << "\t\t"
            << song[i].price
            << "\t\t"
            << song[i].stock;
            cout << endl << endl;
        }
    }
}

void searchYear(int key)
{
    for (int i = 0; i < indeksLagu; i++)
    {
        if (song[i].year == key)
        {
            cout << "No.\tArtist\t\tAlbum Title\t\tGenre\t\tYear\t\tPrice\t\tStock";
            cout << endl
            << i+1 << "\t"
            << song[i].artist
            << "\t\t"
            << song[i].title
            << "\t\t"
            << song[i].genre
            << "\t\t"
            << song[i].year
            << "\t\t"
            << song[i].price
            << "\t\t"
            << song[i].stock;
            cout << endl << endl;
        }
    }
}

void searchMenu()
{
    char keyword[50];
    int keywordYear;
    int choice = get_input <int>(
        "What type of search you want to do?" "\n\n"
        "[1] By Artist" "\n"
        "[2] By Album" "\n"
        "[3] By Genre" "\n"
        "[4] By Year" "\n"
        "[5] Back" "\n");

    switch(choice)
    {
    case 1:
        cin.ignore(256,'\n');
        cout << "\n\nEnter Artist Name : ";
        cin.getline(keyword,50);
        cout << endl;
        searchArtist(keyword);
        cout << endl;
        system("pause");
        system("cls");
        searchMenu();
        break;
    case 2:
        cin.ignore(256,'\n');
        cout << "\n\nEnter Album Title : ";
        cin.getline(keyword,50);
        cout << endl;
        searchAlbum(keyword);
        cout << endl;
        system("pause");
        system("cls");
        searchMenu();
        break;
    case 3:
        cin.ignore(256,'\n');
        cout << "\n\nEnter Genre : ";
        cin.getline(keyword,20);
        cout << endl;
        searchGenre(keyword);
        cout << endl;
        system("pause");
        system("cls");
        searchMenu();
        break;
    case 4:
        cin.ignore(256,'\n');
        cout << "\n\nEnter Year : ";
        cin >> keywordYear;
        cout << endl;
        searchYear(keywordYear);
        cout << endl;
        system("pause");
        system("cls");
        searchMenu();
        break;
    case 5:
        system("cls");
        user_menu();
        break;
    }
}

void lihatLagu()
{
    cout << "No.\tArtist\t\tAlbum Title\t\tGenre\t\tYear\t\tPrice\t\tStock";
    for (int i = 0; i < indeksLagu; i++)
    {
        cout << endl
        << i+1 << "\t"
        << song[i].artist
        << "\t\t"
        << song[i].title
        << "\t\t"
        << song[i].genre
        << "\t\t"
        << song[i].year
        << "\t\t"
        << song[i].price
        << "\t\t"
        << song[i].stock;
    }
    cout << endl << endl;
    system("pause");
    admin_menu();
}

void editData()
{
    int angka,j;
    cout << "Which Number of Data will be edited? : ";
    cin >> angka;
    j = angka-1;
    cin.ignore(256,'\n');
    cout << "Artist Name :\t";
    cin.getline(song[j].artist,50);
    cout << "Album Title :\t";
    cin.getline(song[j].title,50);
    cout << "Genre :\t";
    cin.getline(song[j].genre,20);
    cout << "Year :\t";
    cin >> song[j].year;
    cout << "Price :\t";
    cin >> song[j].price;
    cout << "Stock :\t";
    cin >> song[j].stock;

    cout << "\n\nData Edited Successfully!\n\n";
    system("pause");
    admin_menu();
}

void deleteData()
{
    int angka,j;
    cout << "Which Number of Data will be deleted? : ";
    cin >> angka;
    j = angka-1;
    indeksLagu--;
    for (int i = j; i < indeksLagu; i++)
    {
       song[i] = song[i+1];
    }
    cout << "\nData Deleted Successfully!\n\n";
    system("pause");
    admin_menu();
}

void editProfile()
{
    int choice;
    ulang:
    cout << "\nEdit Your Profile \n\n"
    << "[1] Full Name\n"
    << "[2] Address\n"
    << "[3] Mobile Number\n"
    << "[4] See full profile\n"
    << "[5] Back\n"
    << "> ";
    cin >> choice;

    cin.ignore(256,'\n');

    if (choice == 1)
    {
        cout << "Change Full Name : ";
        getline(cin,profile.fullName);
        goto ulang;
    }
    else if (choice == 2)
    {
        cout << "Change Address : ";
        getline(cin,profile.address);
        goto ulang;
    }
    else if (choice == 3)
    {
        cout << "Change Mobile Number : ";
        getline(cin,profile.mobileNumber);
        goto ulang;
    }
    else if (choice == 4)
    {
        system("cls");
        cout << "\tYour Profile\n\n";
        cout << "Full Name : " << profile.fullName
        << "\nAddress : " << profile.address
        << "\nMobile Number : " << profile.mobileNumber;

        cout << endl << endl;
        system("pause");
        system("cls");
        editProfile();
    }
    else if (choice == 5)
    {
        user_menu();
    }
}

void admin_menu()
{
    system("cls");
    int choice = get_input <int>(
        "\tWelcome Admin!" "\n\n"
        "What do you want to do?" "\n\n"
        "[1] Input Data" "\n"
        "[2] Import Data" "\n"
        "[3] Edit Data" "\n"
        "[4] Show Data" "\n"
        "[5] Delete Data" "\n"
        "[6] Log Out");

    switch (choice)
    {
    case 1:
        inputLagu();
        break;
    case 2:
        importLagu();
        break;
    case 3:
        editData();
        break;
    case 4:
        lihatLagu();
        break;
    case 5:
        deleteData();
    case 6:
        main_menu();
    }

}

void findAlbum()
{
    char choice2 = 'Y';
    char keyword[50];
    int keywordYear;
    int choice = get_input <int>(
        "Find album categories:" "\n\n"
        "[1] By Artist Name" "\n"
        "[2] By Album Title" "\n"
        "[3] By Genre" "\n"
        "[4] By Year" "\n"
        "[5] Back" "\n");

    switch(choice)
    {
        case 1:
            cin.ignore(256,'\n');
            cout << "\n\nEnter Artist Name : ";
            cin.getline(keyword,50);
            cout << endl;
            searchArtist(keyword);
            cout << endl;
            while ((choice2 == 'Y') || (choice2 == 'y'))
            {
                cout << "\nEnter number album to buy = ";
                cin >> buyCart[buyIndex];
                cout << endl << endl << "How much qty to buy? = ";
                cin >> totalItems[buyIndex];
                buyIndex++;
                cout << "Buy album again? (Y/N) = ";
                cin >> choice2;
                system("cls");
            }
            buy_menu();
            break;
        case 2:
            cin.ignore(256,'\n');
            cout << "\n\nEnter Album Title : ";
            cin.getline(keyword,50);
            cout << endl;
            searchAlbum(keyword);
            cout << endl;
            while ((choice2 == 'Y') || (choice2 == 'y'))
            {
                cout << "\nEnter number album to buy = ";
                cin >> buyCart[buyIndex];
                cout << endl << endl << "How much qty to buy? = ";
                cin >> totalItems[buyIndex];
                buyIndex++;
                cout << "Buy album again? (Y/N) = ";
                cin >> choice2;
                system("cls");
            }
            buy_menu();
            break;
        case 3:
            cin.ignore(256,'\n');
            cout << "\n\nEnter Genre : ";
            cin.getline(keyword,20);
            cout << endl;
            searchGenre(keyword);
            cout << endl;
            while ((choice2 == 'Y') || (choice2 == 'y'))
            {
                cout << "\nEnter number album to buy = ";
                cin >> buyCart[buyIndex];
                cout << endl << endl << "How much qty to buy? = ";
                cin >> totalItems[buyIndex];
                buyIndex++;
                cout << "Buy album again? (Y/N) = ";
                cin >> choice2;
                system("cls");
            }
            buy_menu();
            break;
        case 4:
            cin.ignore(256,'\n');
            cout << "\n\nEnter Year : ";
            cin >> keywordYear;
            cout << endl;
            searchYear(keywordYear);
            cout << endl;
            while ((choice2 == 'Y') || (choice2 == 'y'))
            {
                cout << "\nEnter number album to buy = ";
                cin >> buyCart[buyIndex];
                cout << endl << endl << "How much qty to buy? = ";
                cin >> totalItems[buyIndex];
                buyIndex++;
                cout << "Buy album again? (Y/N) = ";
                cin >> choice2;
                system("cls");
            }
            buy_menu();
            break;
        case 5:
            system("cls");
            buy_menu();
            break;
    }
}

int angkaRandom()
{
    int a,b,randomNumber;
    string c = "999000",d,randomString;
    srand((int)time(0));
    a = (rand() % 9) + 1;
    b = (rand() % 9) + 1;
    c += to_string(a);
    d = to_string(b);
    randomString = c + d;
    randomNumber = stoi(randomString);
    return randomNumber;
}

void checkout()
{
    int sumItems = 0;
    int initPrice[buyIndex];
    int sumPrice = 0;
    int finalPrice;
    int finalDiscount = 0;
    cout << "==============================================================================" << endl;
    cout << "                   HIMUSIC - TOKO MUSIK ONLINE MASA DEPAN         " << endl;
    cout << "==============================================================================" << endl;
    cout << "Transaction Number : " << angkaRandom() << ' ' << profile.fullName << endl;
    cout << "Address : " << profile.address << endl;
    cout << "Mobile Number : " << profile.mobileNumber << endl;
    cout << "==============================================================================" << endl;
    cout << "Album Name\t\t\t\t\tTotal\t\tPrice" << endl;
    for (int i = 0; i < buyIndex; i++)
    {
        initPrice[i] = totalItems[i] * song[buyCart[i]-1].price;
        cout
        << song[buyCart[i]-1].artist
        << " - "
        << song[buyCart[i]-1].title
        << "\t\t\t\t"
        << totalItems[i]
        << "\t\tRp "
        << initPrice[i]
        << endl;
        sumItems += totalItems[i];
        sumPrice += initPrice[i];
    }

    int discount = sumPrice * 0.15;

    if (sumItems >= 5)
    {
        finalPrice = sumPrice - discount;
        finalDiscount = 15;
    }
    else
    {
        finalPrice = sumPrice;
        finalDiscount = 0;
        discount = 0;
    }
    cout << "==============================================================================" << endl;
    cout << "TOTAL PRICE\t\t" << sumItems << "\t\t  Rp " << sumPrice << endl;
    cout << "DISCOUNT PROMO\t\t" << finalDiscount << "%\t\t- Rp " << discount << endl;
    cout << "FINAL PRICE\t\t" << "  " << "\t\t  Rp " << finalPrice << endl;
    cout << "==============================================================================" << endl;
    cout << "                     TERIMA KASIH SUDAH PERCAYA KEPADA KAMI        " << endl;
    cout << "                              SALAM MUSIK MASA KINI               " << endl;
    cout << "==============================================================================" << endl;
}

void shoppingCart()
{
    char choice = 'y';

    if (buyIndex == 0)
    {
        cout << "\n\nCart is empty!\n\n";
        system("pause");
        system("cls");
        buy_menu();
    }

    cout << "\tShopping Cart : \n\n";
    cout << "No.\tArtist\t\tAlbum Title\t\tGenre\t\tYear\t\tPrice\t\tStock\t\tBuy Qty";
    for (int i = 0; i < buyIndex; i++)
    {
        cout << endl
        << i+1 << "\t"
        << song[buyCart[i]-1].artist
        << "\t\t"
        << song[buyCart[i]-1].title
        << "\t\t"
        << song[buyCart[i]-1].genre
        << "\t\t"
        << song[buyCart[i]-1].year
        << "\t\t"
        << song[buyCart[i]-1].price
        << "\t\t"
        << song[buyCart[i]-1].stock
        << "\t\t"
        << totalItems[i];
    }
    cout << "\n\nBuy this song? (Y/N)";
    cin >> choice;

    if ((choice == 'Y')||(choice == 'y'))
    {
        for (int i = 0; i < buyIndex; i++)
        {
            song[buyCart[i]-1].stock -= totalItems[i];
        }
        system("cls");
        checkout();
        buyIndex = 0;
        system("pause");
        system("cls");
        buy_menu();
    }
    else
    {
        buy_menu();
    }
}

void buy_menu()
{
    int choice = get_input <int>(
        "What do you want to buy?" "\n\n"
        "[1] Find Albums" "\n"
        "[2] Checkout" "\n"
        "[3] Back" "\n");

    switch (choice)
    {
    case 1:
        findAlbum();
        break;
    case 2:
        shoppingCart();
        //checkout();
        break;
    case 3:
        user_menu();
        break;
    }

}

void user_menu()
{
    system("cls");
    int choice = get_input <int>(
        "\tWelcome To Dashboard!" "\n\n"
        "What do you want to do?" "\n\n"
        "[1] Buy Album" "\n"
        "[2] Edit Profile" "\n"
        "[3] Search Items" "\n"
        "[4] Check Best Seller Albums & Album Of The Day" "\n"
        "[5] Log Out");

    switch (choice)
    {
    case 1:
        buy_menu();
        break;
    case 2:
        editProfile();
        break;
    case 3:
        searchMenu();
        break;
    case 4:
        bestSeller();
    case 5:
        main_menu();
    }

}
