#include <iostream>
#include "studio.h"
using namespace std;

int main()
{
    list_s S;
    create_list_studio(S);
    string C;
    address_s P,R;
    address_j D,E;
    infojadwal IJ;
    string E1;
    int a,b;
    do
    {
        cout<<"MENU UTAMA "<<endl;
        cout<<"1. ADD STUDIO"<<endl;
        cout<<"2. DELETE STUDIO"<<endl;
        cout<<"3. EDIT STUDIO"<<endl;
        cout<<"4. FIND STUDIO"<<endl;
        cout<<"5. SORTING STUDIO "<<endl;
        cout<<"6. VIEW STUDIO "<<endl;
        cout<<"7. ADD JADWAL"<<endl;
        cout<<"8. DELETE JADWAL "<<endl;
        cout<<"9. EDIT JADWAL "<<endl;
        cout<<"10. SORTING JADWAL "<<endl;
        cout<<"11. FIND JADWAL "<<endl;
        cout<<"12. VIEW JADWAL "<<endl;
        cout<<"masukkan pilihan : ";
        cin>>a;
        switch (a)
        {
        case 1 :
        {
            system("cls");
            cout<<"MENU ADD STUDIO "<<endl;
            cout<<"1. ADD FIRST STUDIO"<<endl;
            cout<<"2. ADD LAST STUDIO"<<endl;
            cout<<"3. ADD AFTER STUDIO"<<endl;
            cout<<"4. BACK TO MENU UTAMA"<<endl;
            cout<<endl;
            cout<<"pilihan : ";
            cin>>b;
            switch (b)
            {
            case 1 :
            {
                infotype y;
                cout<<"Masukkan ID Studio : ";
                cin>>y.id_studio;
                cout<<"Masukkan Nama Studio : ";
                cin>>y.nama_studio;
                R=findstudio(S,y.id_studio);
                if(R==nil){
                P=alokasistudio(y);
                insfirststudio(S,P);
                }
                else
                    cout<<"ID sudah ada ";
                break;
            }
            case 2 :
            {
                infotype y;
                cout<<"Masukkan ID Studio : ";
                cin>>y.id_studio;
                cout<<"Masukkan Nama Studio : ";
                cin>>y.nama_studio;
                R=findstudio(S,y.id_studio);
                if(R==nil){
                P=alokasistudio(y);
                inslaststudio(S,P);
                }
                else
                    cout<<"ID sudah ada ";
                break;
            }
            case 3 :
            {
                infotype y;
                address_s Q;
                string C;
                printstudio(S);
                cout<<"Insert Data setelah ID Studio : ";
                cin>>C;
                Q=findstudio(S,C);
                if(Q!=nil) {
                cout<<"Masukkan ID Studio : ";
                cin>>y.id_studio;
                cout<<"Masukkan Nama Studio : ";
                cin>>y.nama_studio;
                P=alokasistudio(y);
                insafterstudio(S,P,Q);}
                else {
                    cout<<"Id tidak ditemukan "<<endl;}
                break;
            }
            case 4 : system("cls");break;
            default : cout<<"Tidak ada dalam pilihan, Program selesai";
            return 0;

            }
            break;
        }
        case 2 :
        {
            system("cls");
            cout<<"MENU DELETE STUDIO "<<endl;
            cout<<"1. DELETE FIRST STUDIO"<<endl;
            cout<<"2. DELETE LAST STUDIO"<<endl;
            cout<<"3. DELETE AFTER STUDIO"<<endl;
            cout<<"4. BACK TO MENU UTAMA"<<endl;
            cout<<"pilihan : ";
            cin>>b;
            switch (b)
            {
            case 1 :
                delfirststudio(S,P);
                break;
            case 2 :
                dellaststudio(S,P);
                break;
            case 3 :{
                string C;
                address_s Q;
                cout<<"Hapus Data setelah ID Studio : ";
                cin>>C;
                Q=findstudio(S,C);
                delafterstudio(S,P,Q);
                break;}
            case 4 : system("cls");break;
            default : cout<<"Tidak ada dalam pilihan, Program selesai";
            return 0;
            }
        }
        break;
        case 7 :
        {
            system("cls");
            cout<<"MENU ADD JADWAL "<<endl;
            cout<<"1. ADD FIRST JADWAL"<<endl;
            cout<<"2. ADD LAST JADWAL"<<endl;
            cout<<"3. ADD AFTER JADWAL"<<endl;
            cout<<"4. BACK TO MENU UTAMA"<<endl;
            cout<<endl;
            cout<<"pilihan : ";
            cin>>b;
            switch (b)
            {
            case 1 :
                cout<<"Insert Jadwal pada ID Studio : ";
                cin>>C;
                P=findstudio(S,C);
                if(P==nil) {
                    cout<<"Data studio tidak ada";
                }
                else {
                barujadwal(IJ);
                D=alokasijadwal(IJ);
                insertfirstjadwal(jadwal(P),D);}
                break;
            case 2 :
                cout<<"Insert Jadwal pada ID Studio : ";
                cin>>C;
                P=findstudio(S,C);
                if(P==nil) {
                    cout<<"Data studio tidak ada";
                }
                else {
                barujadwal(IJ);
                D=alokasijadwal(IJ);
                insertlastjadwal(jadwal(P),D);}
                break;
            case 3 :
                cout<<"Insert Jadwal pada ID Studio : ";
                cin>>C;
                P=findstudio(S,C);
                if(P==nil) {
                    cout<<"Data studio tidak ada";
                }
                else {
                barujadwal(IJ);
                D=alokasijadwal(IJ);
                cout<<"Insert After Data setelah ID jadwal : "; cin>>E1;
                E=findjadwal(jadwal(P),E1);
                insertafterjadwal(jadwal(P),D,E);}
                break;
            case 4 : system("cls");break;
            default : cout<<"Tidak ada dalam pilihan, Program selesai";
            return 0;
            }
            break;
        }
        case 4 :
            system("cls");
            cout<<"Masukkan ID Studio yang dicari : ";
            cin>>C;
            P=findstudio(S,C);
            if(P!=nil)
            {
                cout<<endl<<"ID Studio    : "<<info(P).id_studio<<endl;
                cout<<"NAMA Studio  : "<<info(P).nama_studio<<endl;
            }
            else {
                cout<<"Data tidak ada"<<endl;
            }
            cout<<endl;
            break;
        case 6 :
            system("cls");
            printstudio(S);
            break;
        case 8 :
        {
            system("cls");
            printstudio(S);
            cout<<endl<<endl;
            cout<<"MENU DELETE JADWAL "<<endl;
            cout<<"1. DELETE FIRST JADWAL"<<endl;
            cout<<"2. DELETE LAST JADWAL"<<endl;
            cout<<"3. DELETE AFTER JADWAL"<<endl;
            cout<<"4. BACK TO MENU UTAMA"<<endl;
            cout<<"pilihan : ";
            cin>>b;
            switch (b)
            {
            case 1 :
                cout<<"Delete first Jadwal pada ID Studio : ";
                cin>>C;
                P=findstudio(S,C);
                delfirstjadwal(jadwal(P),D);
                break;
            case 2 :
                cout<<"Delete last Jadwal pada ID Studio : ";
                cin>>C;
                P=findstudio(S,C);
                dellastjadwal(jadwal(P),D);
                break;
            case 3 :
                cout<<"Delete After Jadwal pada ID Studio : ";
                cin>>C;
                P=findstudio(S,C);
                cout<<"Delete After Data setelah ID jadwal : "; cin>>E1;
                E=findjadwal(jadwal(P),E1);
                delafterjadwal(jadwal(P),D,E);
                break;
            case 4 : system("cls");break;
            default : cout<<"Tidak ada dalam pilihan, Program selesai";
            return 0;
            }
        }
        break;
        case 11 :
            printstudio(S);
            cout<<"Masukkan ID Studio : ";
            cin>>C;
            P=findstudio(S,C);
            if(P==nil) {
                cout<<endl<<"Data studio tidak ditemukan"<<endl;
            }
            else {
            cout<<" Find ID jadwal : "; cin>>E1;
            E=findjadwal(jadwal(P),E1);
            if(E!=nil){
            cout<<endl<<"ID Jadwal        : "<<info(E).id_jadwal<<endl;
            cout<<"Hari             : "<<info(E).hari<<endl;
            cout<<"Jam              : "<<info(E).jam.hour<<":"<<info(E).jam.minute<<endl;
            }
            else
            {
                cout<<"Jadwal tidak ada "<<endl;
            }}
            cout<<endl;
            break;
        case 12 :
            printstudio(S);
            cout<<"View Jadwal pada ID Studio : ";
            cin>>C;
            P=findstudio(S,C);
            printjadwal(jadwal(P));
            break;
        case 9 :
            printstudio(S);
            cout<<"Masukkan ID Studio : ";
            cin>>C;
            P=findstudio(S,C);
            if(P==nil) {
                cout<<endl<<"Data studio tidak ditemukan"<<endl;
            }
            else {
            cout<<"ID jadwal : "; cin>>E1;
            E=findjadwal(jadwal(P),E1);
            editjadwal(jadwal(P),E);
        }
        break;
        case 3 :
            system("cls");
            cout<<"Masukkan ID Studio : ";
            cin>>C;
            P=findstudio(S,C);
            if(P==nil){
               cout<<"ID Studio tidak ditemukan "<<endl;
            }
            else
            editstudio(S,P);
            break;
        case 5 : {
            system("cls");
            sortingstudio_asc(S);
            break;
        }
        case 10 :
            cout<<"1. Sorting berdasarkan ID"<<endl
                <<"2. Sorting berdasarkan Jam"<<endl
                <<"3. Back to Menu Utama"<<endl;
            cout<<"Masukkan pilihan : "; cin>>b;
            switch (b){
            case 1 :
            system("cls");
            cout<<"Masukkan ID Studio : ";
            cin>>C;
            P=findstudio(S,C);
            sortingjadwalid(jadwal(P));
            break;
            case 2 :{
            system("cls");
            cout<<"Masukkan ID Studio : ";
            cin>>C;
            P=findstudio(S,C);
            sortingjadwaljam(jadwal(P));
            break;}
            case 3 : break;
            default : cout<<"Tidak ada dalam pilihan, Program selesai"; return 0;
            }
    }
   } while(a<13);
    return 0;
}
