#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>

using namespace std;

void Dosya_olusturma(){

    string dosya_adi;
    cout<<"Olu�turmak istedi�iniz dosyan�n ad�n� giriniz :";
    cin>>dosya_adi;

    ofstream file(dosya_adi.c_str());

    if(file.is_open()){
        cout<<dosya_adi<<" adl� dosyan�z ba�ar�yla olu�turuldu!"<<endl;
        file.close();
    }
    else{
        cout<<"Dosyan�z olu�turulurken bir hata olu�tu. L�tfen tekrar deneyiniz."<<endl;
    }
}

void Dosyaya_yazma(){

    string dosya_adi,icerik;
    cout<<"L�tfen dosya ad�n� giriniz:";
    cin>>dosya_adi;

    ofstream file(dosya_adi.c_str(),ios::app);

    if(file.is_open()){

        cout<<"Dosyaya yazmak istedi�iniz i�eri�i giriniz.(sat�r ba��na 'q' yazarak yaz�y� bitirin.)"<<endl;

        while(true){
            getline(cin,icerik);
            if(icerik =="q"){
                break;
            }
            file<<icerik<<endl;
        }
        cout<<"Dosyaya yazma i�lemi ba�ar�l�!"<<endl;
        file.close();
    }
    else{
        cout<<"Dosya yazma i�lemine bir hata olu�tu.L�tfen tekrar deneyiniz."<<endl;
    }
}

void Dosya_okuma(){

    string dosya_adi,line;
    cout<<"L�tfen dosya ad�n� Giriniz:";
    cin>>dosya_adi;

    ifstream file(dosya_adi.c_str());

    if(file.is_open()){

        cout<<"Dosya ��eri�i: "<<endl;
        while(getline(file,line)){
            cout<<line<<endl;
        }
        file.close();
    }
    else{
        cout<<"Dosya okunurken bir hata olu�tu. L�tfen tekrar deneyiniz."<<endl;
    }
}

void Dosya_sil(){

    string dosya_adi;
    cout<<"Silmek istedi�iniz dosyan�n ad�n� giriniz: ";
    cin>>dosya_adi;

    if(remove(dosya_adi.c_str()) !=0){
        cout<<"Dosya silinirken bir hata olu�tu. L�tfen tekrar deneyiniz."<<endl;
    }
    else{
        cout<<dosya_adi<<" adl� dosya ba�ar�yla silindi!"<<endl;
    }
}
int main()
{
    setlocale(LC_ALL,"Turkish");

    int islem;

    do{
        cout<<"--- DOSYA ��LEMLER� UYGULAMASI ---"<<endl;
        cout<<"1. Dosya Olu�tur"<<endl;
        cout<<"2. Dosya Yazma ��lemi"<<endl;
        cout<<"3. Dosya Okuma ��lemi"<<endl;
        cout<<"4. Dosya Silme ��lemi"<<endl;
        cout<<"5. Uygulamadan ��k��"<<endl;

        cout<<"Yapaca��n�z ��lemi Se�iniz: ";
        cin>>islem;

        switch(islem){

        case 1:
            Dosya_olusturma();
            break;
        case 2:
            Dosyaya_yazma();
            break;
        case 3:
            Dosya_okuma();
            break;
        case 4:
            Dosya_sil();
            break;
        case 5:
            cout<<"Uygulama Kapat�l�yor..."<<endl;
            break;
        default:
            cout<<"Ge�ersiz bir i�lem se�tiniz. L�tfen tekrar deneyin"<<endl;
        }
    }

    while(islem !=5);

    return 0;
}
