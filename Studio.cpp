#include "studio.h"
using namespace std;
void create_list_studio(list_s &L)
{
    first(L)=nil;
}
address_s alokasistudio(infotype x)
{
    address_s P;
    P = new elmstudio;
    info(P).id_studio= x.id_studio;
    info(P).nama_studio= x.nama_studio;
    film(P)=nil;
    create_list(jadwal(P));
    next(P)=nil;
    return P;
}
void create_list(list_j &L)
{
    L.first = NULL;
    L.last = NULL;
}
void barujadwal (infojadwal &x)
{
    cout<<"Input data"<<endl;
    cout<<"ID jadwal            : ";
    cin>>x.id_jadwal;
    cout<<"Hari          : ";
    cin>>x.hari;
    cout<<"Jam         : ";
    cin>>x.jam.hour;
    cout<<"Menit  : ";
    cin>>x.jam.minute;

}
address_j alokasijadwal(infojadwal x)
{
    address_j J;
    J = new elmjadwal;
    info(J).id_jadwal = x.id_jadwal;
    info(J).hari = x.hari;
    info(J).jam.hour = x.jam.hour;
    info(J).jam.minute = x.jam.minute;
    info(J).k[0]=0;
    next(J) = nil;
    prev(J) = nil;
    return J;
}
void insfirststudio(list_s &L, address_s P)
{
    if (first(L)==nil)
    {
        first(L)=P;
    }
    else
        next(P)=first(L);
    first(L)=P;
}

void insafterstudio(list_s &L, address_s P, address_s Prec)
{
    if(next(first(L))!=nil){
      next(P)=next(Prec);
    next(Prec)=P;
    }
    else {
        inslaststudio(L,P);
    }

}

void inslaststudio(list_s &L, address_s P)
{
    address_s Q;
    Q=first(L);
    if(Q==nil)
    {
        insfirststudio(L,P);
    }
    else
    {
        while (next(Q)!=nil)
        {
            Q=next(Q);
        }
        next(Q)=P;
    }
}
address_s findstudio(list_s L, string x)
{
    address_s P;
    P=first(L);
    if(P!=nil) {
    while((info(P).id_studio!=x) and (next(P)!=nil))
    {
        P=next(P);
    }
    if(info(P).id_studio==x)
    {
        return P;
    }
    else
    {
        return nil;
    }
    }
    else {
        return nil;
    }
}
void printstudio (list_s L)
{
    address_s Q;
    Q=first(L);
    if(Q==nil)
    {
        cout<<"DATA KOSONG"<<endl;
    }
    else
    {
        while (Q!=nil)
        {
            cout<<"ID Studio    : "<<info(Q).id_studio<<endl;
            cout<<"Nama Studio  : "<<info(Q).nama_studio<<endl;
            cout<<endl;
            Q=next(Q);
        }
    }
}
void delfirststudio(list_s &L, address_s &P)
{
    P=first(L);
    first(L)=next(first(L));
    next(P)=nil;
    delete P;
}

void delafterstudio(list_s &L, address_s &P, address_s Prec)
{

    P=next(Prec);
    next(Prec)=next(P);
    next(P)=nil;
    delete P;
}

void dellaststudio(list_s &L, address_s &P)
{
    address_s Q;
    Q=first(L);
    while(next(next(Q))!=nil)
    {
        Q=next(Q);
    }
    P=next(Q);
    next(Q)=nil;
    delete P;
}
void insertfirstjadwal(list_j &L, address_j J)
{
    if(first(L) == NULL)
    {
        first(L) = J;
        last(L) = J;
    }
    else
    {
        next(J) = first(L);
        prev(first(L))=J;
        first(L)=J;
    }
}
void insertlastjadwal(list_j &L, address_j J)
{
    if(L.first == NULL)
    {
        L.first = J;
        L.last = J;
    }
    else
    {
        J->prev = L.last;
        next(last(L)) = J;
        L.last = J;
    }
}
void insertafterjadwal(list_j &L, address_j P, address_j Prec)
{
    next(P)=next(Prec);
    prev(P)=Prec;
    prev(next(Prec))=P;
    next(Prec)=P;

}
void printjadwal(list_j L)
{
    address_j Q;
    Q=first(L);
    if(Q==nil)
    {
        cout<<"DATA KOSONG"<<endl;
    }
    else
    {
        while (Q!=nil)
        {
            cout<<"ID Jadwal        : "<<info(Q).id_jadwal<<endl;
            cout<<"Hari             : "<<info(Q).hari<<endl;
            cout<<"Jam              : "<<info(Q).jam.hour<<":"<<info(Q).jam.minute<<endl;
            cout<<endl;
            Q=next(Q);
        }
    }
}
address_j findjadwal(list_j &L,string Es)
{
    address_j P;
    P=first(L);
    if(P==nil)
    {
        return nil;
    }
    else {
    while((info(P).id_jadwal!=Es) and (next(P)!=nil))
    {
        P=next(P);
    }
    if(info(P).id_jadwal==Es)
    {
        return P;
    }
    else
    {
        return nil;
    }}
}
void delfirstjadwal(list_j &L, address_j &PJ)
{
    PJ=first(L);
    first(L)=next(first(L));
    next(PJ)=nil;
    prev(PJ)=nil;
    delete PJ;
}
void dellastjadwal(list_j &P,address_j &PJ)
{
    PJ=last(P);
    last(P)=prev(last(P));
    prev(PJ)=nil;
    next(last(P))=nil;
    delete PJ;
}
void delafterjadwal(list_j &L,address_j &PJ,address_j Prec)
{
    PJ=next(Prec);
    next(Prec)=next(PJ);
    next(PJ)=nil;
    prev(PJ)=nil;
    delete PJ;
}
void editstudio (list_s &L,address_s &J)
{
    cout<<"NAMA STUDIO : "; cin>>info(J).nama_studio;
    cout<<"DATA UPDATING!"<<endl;
}

void editjadwal (list_j &L,address_j &J)
{
    int a;
    string Ed;
    address_j E;
    cout<<"1. Edit semua "<<endl
        <<"2. Edit Hari Jadwal"<<endl
        <<"3. Edit Jam dan Menit Jadwal"<<endl;
    cout<<"Masukkan pilihan : ";
    cin>>a;
    switch(a)
    {
    case 1 :
        cout<<"Hari      : ";
        cin>>info(J).hari;
        cout<<"Jam       : ";
        cin>>info(J).jam.hour;
        cout<<"Menit     : ";
        cin>>info(J).jam.minute;
        break;
    case 2 :
        cout<<"Hari      : ";
        cin>>info(J).hari;
        cout<<"Data telah di Update !";
        break;
    case 3 :
        cout<<"Jam       : ";
        cin>>info(J).jam.hour;
        cout<<"Menit     : ";
        cin>>info(J).jam.minute;
        cout<<"Data telah di Update !";
        break;
    }

}
void sortingstudio_asc(list_s &L)
{
    if(first(L)!=nil){
	address_s P = first(L);
	address_s Q = next(P);
	address_s imin = nil;
	while(next(P)!= NULL)
	{
		imin = next(P);
		while(Q != NULL)
		{
			if(info(Q).id_studio < info(imin).id_studio)
				imin = Q;
            Q=next(Q);
		}
		if(info(P).id_studio > info(imin).id_studio) {
			swap(info(P), info(imin));
			swap(jadwal(P),jadwal(imin));
		}
		P = next(P);
		Q=next(P);
	}
	printstudio(L);
    }
    else {
        cout<<"List Studio kosong "<<endl<<endl;
    }
}
void sortingjadwalid(list_j &L)
{
	address_j P = first(L);
	address_j Q = next(P);
	address_j imin = nil;
	while(next(P)!= NULL)
	{
		imin = next(P);
		while(Q != NULL)
		{
			if(info(Q).id_jadwal < info(imin).id_jadwal)
				imin = Q;
            Q=next(Q);
		}
		if(info(P).id_jadwal > info(imin).id_jadwal) {
			swap(info(P), info(imin));
		}
		P = next(P);
		Q=next(P);
	}
	printjadwal(L);
}
void sortingjadwaljam(list_j &L)
{
	address_j P = first(L);
	address_j Q = next(P);
	address_j imin = nil;
	while(next(P)!= NULL)
	{
		imin = next(P);
		while(Q!= NULL)
		{
			if(info(Q).jam.hour < info(imin).jam.hour){
            imin = Q;}
            else if(info(Q).jam.hour == info(imin).jam.hour){
                if(info(Q).jam.minute < info(imin).jam.minute) {
                    imin = Q;
                }
            }
            Q=next(Q);
		}
		if(info(P).jam.hour > info(imin).jam.hour) {
			swap(info(P), info(imin));
		}
		else if(info(P).jam.hour == info(imin).jam.hour){
                if(info(P).jam.minute > info(imin).jam.minute) {
                    swap(info(P), info(imin));
                }
		}
		P = next(P);
		Q=next(P);
	}
	printjadwal(L);
}
