#include <iostream>
#include <cstdlib>
#define max 10
using namespace std;

struct mahasiswa
{
	string nama;
	string nim;
	float ipk;
};

struct tumpukan
{
    int atas;
    
}t;

void awal()
{
    t.atas=-1;
}

int kosong()
{
    if (t.atas==-1)
        return 1;
    else
        return 0;
}
int penuh()
{
    if (t.atas==max-1)
        return 1;
    else    
        return 0;
}

void nama(mahasiswa *mhs)
{
	cout << "Inputkan Nama Mahasiswa: ";
	cin.ignore();
	getline(cin, mhs->nama);
}
void nim(mahasiswa *mhs)
{
	cout << "Inputkan NIM Mahasiswa: ";
	cin >> mhs->nim;
	cout << endl;
}

float calculate(float *TOT,mahasiswa *mhs) 
{ 	
	return mhs->ipk=*TOT/5/25;	
}

void hapus()
{
    if(kosong()==0)
    {
        cout << "Data teratas sudah terambil";
        t.atas--;
    }
    else
        cout << "Data Kosong";
}

void bersih()
{
    t.atas=-1;
    cout<<"tumpukan kosong";
}
void input(mahasiswa *mhs)
{	
	string matkul[5] = {"Pemrograman","Sistem Operasi","Struktur Data",
						"Bahasa Inggris","Hardware/Software"};				
	float *nilai = new float[max*5];
	float tot[max];
	int total; 	
	
		cout<<endl;
		cout << "Mahasiswa ke-" << (t.atas + 1) <<endl;
		total=0;
		nama(mhs + t.atas);
		nim(mhs + t.atas);
		
		for(int j=0; j<5; j++)
		{
			cout << "Nilai Mata kuliah "<<matkul[j]<<": ";
			cin>>*(nilai+(t.atas*5+j));
			total = total + nilai[(t.atas*5+j)];	
		}
		tot[t.atas]=total; 
		calculate(&tot[t.atas],(mhs + t.atas));
	
	delete[] nilai;
}

void push(mahasiswa *mhs)
{
    if(kosong()==1)
    {
        t.atas++;
        input(mhs);
        cout<<"Data "<<(mhs + t.atas)->nama<<" Masuk ke stuck";
    }
    else if (penuh()==0)
    {
        t.atas++;
        input(mhs);
        cout<<"Data "<<(mhs + t.atas)->nama<<" Masuk ke stuck"; 
    }
    else
        cout<<"Tumpukan penuh";
}


void sort(mahasiswa *mhs){
	
	mahasiswa temp;
	int jika=0;
	balik:
	cout<<endl;
	cout<<"Metode sorting"<<endl;
	cout<<"1. Bubble Sort"<<endl;
	cout<<"2. Insertion sort"<<endl;
	cout<<"3. selection Sort"<<endl<<endl;
	cout<<"Inputkan Metode yang ingin digunakan dari 1-3: ";
	cin>>jika;
	if(jika==1)
	{
		
		for(int i=0;i<(t.atas-1);i++){
			for(int j=0;j<(t.atas-1);j++){
				if((mhs + j)->ipk < (mhs+j+1)->ipk){
				
				temp = mhs[j];
                mhs[j] = mhs[j+1];
                mhs[j+1] = temp;
				}
			}
		}
	cout <<"\n(Sorting menggunakan Metode Bubble Sort)"<< endl;
	}else if(jika==2)
	{
		string tempnama, tempnim;
		float sort;
		int loot;
		for(int i=0; i<t.atas; i++){
		sort = (mhs + i)->ipk;
		tempnim = (mhs + i)->nim;
		tempnama = (mhs + i)->nama;
		loot = i-1;
		while((mhs + loot)->ipk < sort && loot>=0)
		{
			(mhs + loot + 1)->ipk = (mhs + loot)->ipk; 
			(mhs + loot + 1)->nim = (mhs + loot)->nim; 
			(mhs + loot + 1)->nama = (mhs + loot)->nama; 
			loot--;	
		}
		(mhs + loot + 1)->ipk = sort;
		(mhs + loot + 1)->nim = tempnim;
		(mhs + loot + 1)->nama = tempnama;	
		}	
	cout <<"\n(Sorting menggunakan Metode Insertion sort)"<< endl;	
	}else if(jika==3)
	{
		int maks;
		for(int i=0; i<t.atas; i++)
		{	
			maks = i;
			for(int j=i+1; j<t.atas; j++){
				if( (mhs + maks)->ipk < (mhs + j)->ipk)
				maks=j;
			}
			if((mhs + i)->ipk != (mhs + maks)->ipk)
			{
				temp = (mhs[i]);
                mhs[i] = mhs[maks];
                mhs[maks] = temp;
			}			
		}	
	cout <<"\n(Sorting menggunakan Metode Selection sort)"<< endl;						
	}else{
	cout<<"Input yang anda masukan tidak sesuai, silahkan di input ulang"<<endl;
	goto balik;
	}
}
void ranking (mahasiswa *mhs){
	for (int i=0; i<t.atas; i++){
		cout<<"Data nilai mahasiswa ke-"<<(i+1)<<endl;
		cout <<"Nama Mahasiswa: "<< (mhs + i)->nama<<endl;
		cout << "NIM: "<<(mhs + i)->nim<<endl;	
    	cout<<"IPK : "<<(mhs + i)->ipk<<endl;	
		cout<<endl;			
	}
}
void show (mahasiswa *mhs){
	if(kosong()==0)
    {
		cout <<"Nama-nama Mahasiswa: "<< endl;	
			for (int i=t.atas;i>=0;i--){
			cout <<(i+1)<<". "<<(mhs + i)->nama<<endl;			
		}
	}
	else
	{
		cout << "\nTumpukan kosong";
	}
        
}

void find (mahasiswa *mhs){
	string cari, posisinama,posisinim;
	float posisiipk;	
	cout<<"\nMasukan data yang dicari: ";
	cin>>cari;
		int ketemu=0;
		for(int i=0; i<t.atas; i++){
			if((mhs + i)->nama == cari)
			{
			ketemu = 1;
			posisinama = (mhs + i)->nama;
			posisinim = (mhs + i)->nim;
			posisiipk = (mhs + i)->ipk;
			i = t.atas;
			}
		}
		if(ketemu == 0)
		{
		cout<<"Data Mahasiswa tidak ditemukan";
		}
		else
		{
		system("cls");
		cout<<"Menampilkan data mahasiswa"<<endl<<endl;
		cout <<"Nama Mahasiswa: "<< posisinama<<endl;
		cout << "NIM: "<<posisinim<<endl;	
    	cout<<"IPK : "<<posisiipk<<endl;	
		cout<<endl;	
	}
}

int main()
{
	mahasiswa mhs[max];
	int pil;
    awal();
    do
    {
        cout << "1. Input\n2. Hapus\n3. Tampil\n4. ";
        cout << "Bersihkan\n5. Keluar\nMasukkan pilihan :";
        cin >> pil;
        switch(pil)
        {
            case 1: 
				push(mhs);
				break;
            case 2: 
				hapus();
                break;
            case 3: 
				show (mhs);
                break;
            case 4:
				bersih();
                break;
            case 5: 
				cout << "Terimakasih"; 
        }
    getchar();
    cout<<endl;
    cout<<endl;  
    }
    while(pil!=5);

	
	//sort (mhs);
	//ranking (mhs);
	//show (mhs);
	//find (mhs);

	return 0;
}
