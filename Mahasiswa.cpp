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
        cout << "\nData teratas sudah terambil";
        t.atas--;
    }
    else
        cout << "\nData Kosong";
}
void bersih()
{
    t.atas=-1;
    cout<<"\ntumpukan kosong";
}
// deklarasi fungsi input 
void input(mahasiswa *mhs); 
// deklarasi fungsi push
void push(mahasiswa *mhs);
// deklarasi fungsi sort
void sort(mahasiswa *mhs);
// deklarasi fungsi rangking 
void ranking (mahasiswa *mhs);
// deklarasi fungsi show
void show (mahasiswa *mhs);
// deklarasi fungsi find
void find (mahasiswa *mhs);

// Main Program 
int main()
{
	
	mahasiswa mhs[max];
	int pil;
    awal();
    do
    {	
		// swicth case tampilan menu
        cout << "1. Input\n2. Hapus\n3. Tampil\n4. ";
        cout << "Bersihkan\n5. Sorting\n6. Mencari Data\n7. ";
		cout << "Keluar\nMasukkan pilihan :";
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
		sort (mhs);
		break;
	    case 6:
		find (mhs);
		break;
	    case 7:
		cout << "Terimakasih"; 

        }
    getchar();
    cout<<endl;
    cout<<endl;  
    }
    while(pil!=7);
	// ranking (mhs);
	return 0;
}

void input(mahasiswa *mhs)
{	
	// Deklarasi variabel lokal
	string matkul[5] = {"Pemrograman","Sistem Operasi","Struktur Data",
						"Bahasa Inggris","Hardware/Software"};	
	float tot[max];
	int total; 	

	// alokasi blok memori nilai 			
	float *nilai = new float[max*5];
		// Input nama dan nim
		cout<<endl;
		cout << "Mahasiswa ke-" << (t.atas + 1) <<endl;
		total=0;
		nama(mhs + t.atas);
		nim(mhs + t.atas);
		
		for(int j=0; j<5; j++)
		{
			// input nilai Mata Kuliah Mahasiswa
			cout << "Nilai Mata kuliah "<<matkul[j]<<": ";
			cin>>*(nilai+(t.atas*5+j));

			// Menjumlahkan nilkai mata kuliah mahasiswa
			total = total + nilai[(t.atas*5+j)];	
		}
		tot[t.atas]=total; 

		// menghitung ipk mahasiswa
		calculate(&tot[t.atas],(mhs + t.atas));

	// bebaskan blok memori nilai mata kuliah yang dialokasikan
	delete[] nilai;
}

void push(mahasiswa *mhs)
{	
	// jika variabel kosong sama dengan 1 atau true
    if(kosong()==1)
    {
        t.atas++;
        input(mhs);
        cout<<"\nData "<<(mhs + t.atas)->nama<<" Masuk ke stuck";
    }
	// jika variabel peuh sama dengan 0 atau false
    else if (penuh()==0)
    {
        t.atas++;
        input(mhs);
        cout<<"\nData "<<(mhs + t.atas)->nama<<" Masuk ke stuck"; 
    }
    else
        cout<<"Tumpukan penuh";
}

void sort(mahasiswa *mhs)
{
	// Deklarasi Variabel loka
	mahasiswa temp;
	int jika;
	// tujuan dari label goto balik
	balik:
	cout<<endl;
	cout<<"Metode sorting"<<endl;
	cout<<"1. Bubble Sort\n2. Insertion sort\n3. selection Sort"<<endl<<endl;
	cout<<"Inputkan Metode yang ingin digunakan dari 1-3: ";
	cin>>jika;
	if(jika==1)
	{	
		// Bubble Sort
		for(int i=0;i<=(t.atas-1);i++){
			for(int j=0;j<=(t.atas-1);j++){
				if((mhs + j)->ipk < (mhs+j+1)->ipk){
				temp = mhs[j];
                		mhs[j] = mhs[j+1];
                		mhs[j+1] = temp;
				}
			}
		}
	cout<<"\nData sudah disortir menggunakan metode bubble sort";
	}else if(jika==2)
	{
		// Insertion Sort
		string tempnama, tempnim;
		float sort;
		int loot;
		for(int i=0; i<=t.atas; i++){
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
	cout<<"\nData sudah disortir menggunakan metode Insertion Sort";
	}else if(jika==3)
	{
	// Selection sort
	int maks;
	for(int i=0; i<=t.atas; i++)
	{	
		maks = i;
		for(int j=i+1; j<=t.atas; j++){
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
	cout<<"\nData sudah disortir menggunakan metode Selection sort";			
	}else{
	cout<<"Input yang anda masukan tidak sesuai, silahkan di input ulang"<<endl;
	//  pernyataan untuk melompat ke tujuan goto balik
	goto balik;
	}
}

void ranking (mahasiswa *mhs)
{
	if(kosong()==0)
    	{
	// Menampilkan data nama, nim, ipk Mahasiswa
	for (int i=0; i<=t.atas; i++){
		cout<<"Data nilai mahasiswa ke-"<<(i+1)<<endl;
		cout <<"Nama Mahasiswa: "<< (mhs + i)->nama<<endl;
		cout << "NIM: "<<(mhs + i)->nim<<endl;	
    		cout<<"IPK : "<<(mhs + i)->ipk<<endl;	
		cout<<endl;	
		}		
	}else{
		cout << "\nTumpukan kosong";
	}
}

void show (mahasiswa *mhs)
{
	if(kosong()==0)
	{
	// Menampilkan data nama mahasiswa
	cout <<"\nNama-nama Mahasiswa: "<< endl;	
		for (int i=0;i<=t.atas;i++){
		cout <<(i+1)<<". "<<(mhs + i)->nama<<endl;			
		}
	}
	else
	{
		cout << "\nTumpukan kosong";
	}
        
}

void find (mahasiswa *mhs)
{	
	if(kosong()==0)
	{
		// Mencari data mahasiswa dengan Sequential Search
		string cari, posisinama,posisinim;
		float posisiipk;	
		cout<<"\nMasukan data yang dicari: ";
		cin>>cari;
		int ketemu=0;
		for(int i=0; i<=t.atas; i++){
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
		// Menampilkan nama,nim,ipk yang dicari
		cout<<"\nMenampilkan data mahasiswa"<<endl<<endl;
		cout <<"Nama Mahasiswa: "<< posisinama<<endl;
		cout << "NIM: "<<posisinim<<endl;	
    	cout<<"IPK : "<<posisiipk<<endl;
		}
	}
	else
	{
		cout << "\nTumpukan kosong";
	}
}
