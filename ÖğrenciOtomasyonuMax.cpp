#include <iostream>
#include <vector>
#include <string>

using namespace std;
struct ogrenci{
    string isim;
    int yas;
    double notu;
};

void ogrenciListele(const vector<ogrenci>& x){
    string notDurumu;
    for(int i=0;i<x.size();i++){
        if(x[i].notu>=50){
            notDurumu="Sınıfı geçti.";
        }
        else{
            notDurumu="Sınıfta kaldı.";
        }
        cout<<endl<<i+1<<". "<<x[i].isim<<" | "<<x[i].yas<<" yaş"<<" | "<<x[i].notu<<" | "<<notDurumu<<endl;
    }
}

void ogrenciBul(vector<ogrenci> x, string isim){
    bool bulundu=false;
    for(int i=0;i<x.size();i++){
        if(isim==x[i].isim){
            bulundu = 1;
            cout<<"\nÖğrenci başarıyla bulundu"<<endl;
            cout<<"\nÖğrenci ismi : "<<x[i].isim<<endl;
            cout<<"Öğrencinin yaşı : "<<x[i].yas<<endl;
            cout<<"Öğrencinin notu : "<<x[i].notu<<endl;
        }
    }
    if(bulundu==false){
        cout<<"\nÖğrenci bulunamadı.";
    }
}
  
double ortalamaBul(vector<ogrenci> x){
    double toplam=0;
    for(int i=0;i<x.size();i++){
        toplam +=x[i].notu;
    }
    return toplam/x.size();
}
    
int enYuksekBul(vector<ogrenci> x){
    int enYuksekIndeks=0;
    int enYuksek=x[0].notu;
    for(int i=0;i<x.size();i++){
        if(x[i].notu>enYuksek){
            enYuksek=x[i].notu;
            enYuksekIndeks=i;
        }
    }
return enYuksekIndeks;
}

int enDusukBul(vector<ogrenci> x){
    int enDusukIndeks=0;
    int enDusuk=x[0].notu;
    for(int i=0;i<x.size();i++){
        if(x[i].notu<enDusuk){
            enDusuk=x[i].notu;
            enDusukIndeks=i;
        }
    }
return enDusukIndeks;
}
    
int main(){
    vector<ogrenci> ogrenciler;
    int secim;

    do{
        cout<<"\n---==== ÖĞRENCİ OTOMASYONU =====---"<<endl;
        cout<<"\n1 - Öğrenci ekle"<<endl;
        cout<<"2 - Öğrencileri listele"<<endl;
        cout<<"3 - Öğrenci ara"<<endl;
        cout<<"4 - Sınıf ortalamasını göster"<<endl;
        cout<<"5 - En yüksek notu göster"<<endl;
        cout<<"6 - En düşük notu göster"<<endl;
        cout<<"7 - Öğrenci sayısını göster"<<endl;
        cout<<"8 - Çıkış"<<endl;
        cin>>secim;
        
        switch(secim){
            case 1:{
            int yas;
            double notu;
            string isim;
            cout<<"Öğrencinin ismini giriniz : ";
            cin.ignore();
            getline(cin,isim);
            cout<<"Öğrencinin yaşını giriniz : ";
            cin>>yas;
            cout<<"Öğrencinin notunu giriniz : ";
            cin>>notu;
            
            ogrenci yeniOgrenci;
            yeniOgrenci.isim=isim;
            yeniOgrenci.yas=yas;
            yeniOgrenci.notu=notu;
            ogrenciler.push_back(yeniOgrenci);
            break;
            }

            case 2:{ 
            if(ogrenciler.empty()){
            cout<<"\nHenüz öğrenci eklenmedi"<<endl;
            }else{
            ogrenciListele(ogrenciler);
            }
            break;
            }

            case 3:{
            if(ogrenciler.empty()){
            cout<<"\nHenüz öğrenci eklenmedi"<<endl;
            }else{
            string aranan;
            cout<<"\nAramak istediğiniz öğrencinin ismini giriniz : ";
            cin.ignore();
            getline(cin,aranan);
            ogrenciBul(ogrenciler,aranan);
            }
            break;
            }

            case 4:{
            if(ogrenciler.empty()){
            cout<<"\nHenüz öğrenci eklenmedi"<<endl;
            }else{
            cout<<"\nSınıf ortalaması : "<<ortalamaBul(ogrenciler)<<endl;
            }
            break;
            }

            case 5:{if(ogrenciler.empty()){
            cout<<"\nHenüz öğrenci eklenmedi"<<endl;
            }else{
            int indeks = enYuksekBul(ogrenciler);
            cout<<"\nEn yüksek not : "<<ogrenciler[indeks].notu<<"\nNotun sahibi : "<<ogrenciler[indeks].isim<<endl;
            }
            break;
            }

            case 6:{
            if(ogrenciler.empty()){
            cout<<"\nHenüz öğrenci eklenmedi"<<endl;
            }else{
            int indeks = enDusukBul(ogrenciler);
            cout<<"\nEn düşük not : "<<ogrenciler[indeks].notu<<"\nNotun sahibi : "<<ogrenciler[indeks].isim<<endl;
            }
            break;
            }

            case 7:{
            cout<<"\nÖğrenci sayısı : "<<ogrenciler.size()<<endl;
            break;
            }

            case 8:
            cout<<"\nÇıkış yapılıyor..."<<endl;
            break;

            default :
            cout<<"\nGeçersiz işlem.";

        }
    }while(secim !=8);

return 0;
}