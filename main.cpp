#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>

using namespace std;

void Dosya_olusturma(){

    string dosya_adi;
    cout<<"Oluþturmak istediðiniz dosyanýn adýný giriniz :";
    cin>>dosya_adi;

    ofstream file(dosya_adi.c_str());

    if(file.is_open()){
        cout<<dosya_adi<<" adlý dosyanýz baþarýyla oluþturuldu!"<<endl;
        file.close();
    }
    else{
        cout<<"Dosyanýz oluþturulurken bir hata oluþtu. Lütfen tekrar deneyiniz."<<endl;
    }
}

void Dosyaya_yazma(){

    string dosya_adi,icerik;
    cout<<"Lütfen dosya adýný giriniz:";
    cin>>dosya_adi;

    ofstream file(dosya_adi.c_str(),ios::app);

    if(file.is_open()){

        cout<<"Dosyaya yazmak istediðiniz içeriði giriniz.(satýr baþýna 'q' yazarak yazýyý bitirin.)"<<endl;

        while(true){
            getline(cin,icerik);
            if(icerik =="q"){
                break;
            }
            file<<icerik<<endl;
        }
        cout<<"Dosyaya yazma iþlemi baþarýlý!"<<endl;
        file.close();
    }
    else{
        cout<<"Dosya yazma iþlemine bir hata oluþtu.Lütfen tekrar deneyiniz."<<endl;
    }
}

void Dosya_okuma(){

    string dosya_adi,line;
    cout<<"Lütfen dosya adýný Giriniz:";
    cin>>dosya_adi;

    ifstream file(dosya_adi.c_str());

    if(file.is_open()){

        cout<<"Dosya Ýçeriði: "<<endl;
        while(getline(file,line)){
            cout<<line<<endl;
        }
        file.close();
    }
    else{
        cout<<"Dosya okunurken bir hata oluþtu. Lütfen tekrar deneyiniz."<<endl;
    }
}

void Dosya_sil(){

    string dosya_adi;
    cout<<"Silmek istediðiniz dosyanýn adýný giriniz: ";
    cin>>dosya_adi;

    if(remove(dosya_adi.c_str()) !=0){
        cout<<"Dosya silinirken bir hata oluþtu. Lütfen tekrar deneyiniz."<<endl;
    }
    else{
        cout<<dosya_adi<<" adlý dosya baþarýyla silindi!"<<endl;
    }
}
int main()
{
    setlocale(LC_ALL,"Turkish");

    int islem;

    do{
        cout<<"--- DOSYA ÝÞLEMLERÝ UYGULAMASI ---"<<endl;
        cout<<"1. Dosya Oluþtur"<<endl;
        cout<<"2. Dosya Yazma Ýþlemi"<<endl;
        cout<<"3. Dosya Okuma Ýþlemi"<<endl;
        cout<<"4. Dosya Silme Ýþlemi"<<endl;
        cout<<"5. Uygulamadan Çýkýþ"<<endl;

        cout<<"Yapacaðýnýz Ýþlemi Seçiniz: ";
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
            cout<<"Uygulama Kapatýlýyor..."<<endl;
            break;
        default:
            cout<<"Geçersiz bir iþlem seçtiniz. Lütfen tekrar deneyin"<<endl;
        }
    }

    while(islem !=5);

    return 0;
}
