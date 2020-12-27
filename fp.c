#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct akun{
	char nama[40];
	char username[16];
	char password[16];
	int simpanan;
	int pinjaman;
	int besarcicilan;
	int cicilan;
	char kelamin[15];
	char pekerjaan[12];
	char nohp[13];
};
typedef struct akun anggota;

//Membuat array akun sebanyak 20 anggota
anggota akun[20];
//indeks=indeks untuk input data.
//indeks juga diguanakan untuk melacak banyak data.
int indeks=0;
int input;

void buatAkun(){
	printf("============Buat Akun============\n");
	printf("Anda akan membayar simpanan pokok sebesar Rp.1.000.000 pada koperasi.\n");
	printf("----------------------------------------------\n\n");
	printf("Nama : ");
	scanf(" %[^\n]%*c", &akun[indeks].nama);
	printf("------------------------------------\n");
	printf("Anda Laki-Laki atau perempuan?\n");
	printf("1. Laki Laki\n");
	printf("2. Perempuan\n");
	kelamin:
	printf("Input : ");
	scanf("%d",&input);
	if(input==1){
		strcpy(akun[indeks].kelamin,"Laki-laki");
	}
	else if(input==2){
		strcpy(akun[indeks].kelamin,"Perempuan");
	}
	else{
		goto kelamin;
	}
	printf("------------------------------------\n");
	printf("Pekerjaan : ");
	scanf(" %[^\n]%*c", &akun[indeks].pekerjaan);
	printf("------------------------------------\n");
	printf("Nomor HP : ");
	scanf(" %[^\n]%*c", &akun[indeks].nohp);
	printf("------------------------------------\n\n");
	printf("Username : ");
	scanf(" %[^\n]%*c", &akun[indeks].username);
	//Pengecekan username duplikasi
	int i=0;
	for(i=0; i<indeks; i++){
		if(!strcmp(akun[i].username, akun[indeks].username)){
			printf("Error.");
			getch();
			system("cls");
			return;
		}
	}
	if(!strcmp(&akun[indeks].username, "admin")){
		printf("Error.");
		getch();
		system("cls");
		return;
	}
	printf("Password : ");
	scanf(" %[^\n]%*c", &akun[indeks].password);
	akun[indeks].simpanan=0;
	akun[indeks].pinjaman=0;
	akun[indeks].cicilan=0;
	indeks++;
}

int cekLogin(char *user, char *password){
	int i=0;
	if(password==NULL){
		for(i=0; i<indeks; i++){
			if(!strcmp(akun[i].username, user)){
				return i;
			}
		}
		return -1;
	}
	else{
		for(i=0; i<indeks; i++){
			if(!strcmp(akun[i].username, user)){
				if(!strcmp(akun[i].password, password)){
					return i;
				}
			}
		}
		return -1;
	}
}

void hapus(int x){
	for(x;x<indeks;x++){
		strcpy(akun[x].nama,akun[x+1].nama);
		strcpy(akun[x].kelamin,akun[x+1].kelamin);
		strcpy(akun[x].pekerjaan,akun[x+1].pekerjaan);
		strcpy(akun[x].nohp,akun[x+1].nohp);
		strcpy(akun[x].username,akun[x+1].username);
		strcpy(akun[x].password,akun[x+1].password);
		akun[x].pinjaman=akun[x+1].pinjaman;
		akun[x].simpanan=akun[x+1].simpanan;
		akun[x].cicilan=akun[x+1].cicilan;
		akun[x].besarcicilan=akun[x+1].besarcicilan;
	}
	indeks-=1;
}

void tampil(){
	int i=0;
	if(indeks>0){
		for(i=0;i<indeks;i++){
			printf("==========Data Anggota %d=========\n", i+1);
			printf("Nama\t\t: %s\n",akun[i].nama);
			printf("Kelamin\t\t: %s\n",akun[i].kelamin);
			printf("Pekerjaan\t: %s\n",akun[i].pekerjaan);
			printf("Nomor HP\t: %s\n",akun[i].nohp);
			printf("-----------------------------\n");
			printf("Tabungan\t: %d\n",akun[i].simpanan);
			printf("Pinjaman\t: %d\n",akun[i].pinjaman);
			printf("Besar Cicilan\t: %d\n",akun[i].besarcicilan);
			printf("-----------------------------\n");
			printf("username\t: %s\n",akun[i].username);
			printf("password\t: %s\n",akun[i].password);
			printf("=====================================\n\n");	
		}
	}
	else{
		printf("============Daftar Anggota============\n\n");
		printf("Tidak ada anggota...\nSilahkan tambahkan anggota terlebih dahulu...\n");
	}
}

//Former codeblock for jumpsearch method by username
/*
int min(int num1, int num2) 
{
    return (num1 > num2 ) ? num2 : num1;
}

int cariData(char *x){
	int jump = sqrt(indeks);
	int back = 0;
	while(min(jump, indeks)-1 < indeks){
		back = jump;
		jump += sqrt(indeks);
		if (back >= indeks){
			return -1;
		}
	}
	while (back < indeks){
		back++;
		
		if(back == min(jump, indeks)){
			return -1;
		}
	}
		
	if (akun[back].username == x){
		return back;
		printf("Ketemu!!");
	}
	return -1;
}
*/

int main(){
	//variabel program
	char user[16];
	char password[16];
	int login=-1;
	int keluar=0;
	
	//Atribut koperasi
	int kas=5000000, pinjam, cicil;
	
	do{
		menu:
		if(login==-1){
			printf("============Koperasi============\n");
			printf("Selamat datang di program koperasi Maju Mundur!\n");
			printf("Silahkan login terlebih dahulu!\n");
			printf("---------------------------------\n\n");
			printf("1. Login\n");
			printf("2. Buat akun\n");
			printf("=================================\n");
			printf("0. Keluar\n\n");
			printf("Input : ");
			scanf("%d", &input);
			system("cls");
			
			if(input==1){
				login:
				printf("============Koperasi============\n");
				printf("----------Login Anggota---------\n\n");
				printf("Username : ");
				scanf(" %[^\n]%*c", &user);
				//Pengecekan username pada akun
				//Login Admininstrator
				if(!strcmp(user, "admin")){
					printf("Password : ");
					scanf(" %[^\n]%*c", &password);
					if(!strcmp(password, "admin123")){
						login=-2;
						printf("Login adminstrator terdeteksi.");
						getch();
						system("cls");
					}
					else{
						printf("Password Salah!");
						getch();
						system("cls");
						goto login;
					}
				}
				//Jika salah :
				else if(cekLogin(user, NULL)==-1){
					printf("\nUsername yang anda masukkan tidak ada dalam database..");
					getch();
					system("cls");
					goto menu;
				}
				//Jika cocok :
				else{
					printf("Password : ");
					scanf(" %[^\n]%*c", &password);
					//Pencocokan username dengan password
					//-1=Salah, ekspektasi variabel login adalah indeks dari array akun.
					login=cekLogin(user, password);
					if(login==-1){
						printf("Password Salah!");
						getch();
						system("cls");
						goto login;
					}
					else{
						printf("Login telah berhasil!");
						getch();
						system("cls");
						goto menu;		
					}	
				}
			}
			else if(input==2){
				buatAkun();
				kas+=1000000;
				system("cls");
			}
			else if(input==0){
				keluar=1;
				system("cls");
				printf("============Koperasi============\n");
				printf("Terima kasih telah menggunakan aplikasi Koperasi Maju Mundur.");
				break;
			}
			else{
				goto menu;
			}
		}
		
		else if(login==-2){
			printf("============ADMINISTRATOR============\n");
			printf("==============Koperasi===============\n");
			printf("1. Manajemen Koperasi\n");
			printf("2. Manajemen Akun Anggota\n\n");
			printf("0. Log Out\n\n");
			scanf("%d", &input);
			system("cls");
			if(input==1){
				koperasi:
				printf("============ADMINISTRATOR============\n");
				printf("1.Kas Koperasi\n");
				printf("-\n");
				printf("-\n");
				printf("0. Kembali\n\n");
				scanf("%d", &input);
				system("cls");
				if(input==1){
					printf("============Koperasi============\n");
					printf("Kas Koperasi saat ini : Rp.%d\n\n", kas);
					printf("Modal Awal Koperasi : Rp.5000000\n");
					printf("Penghasilan dari Simpanan Pokok sebesar : Rp.%d\n", indeks*100000);
					
					int totalpinjam=0, i, totalsimpan=0;
					for(i=0; i<indeks; i++){
						totalpinjam+=akun[i].pinjaman;
						totalsimpan+=akun[i].simpanan;
					}
					printf("Total Simpanan Anggota : Rp.%d\n",totalsimpan);
					printf("Banyaknya cicilan yang belum lunas : -%d\n",totalpinjam);
					printf("---------------------------------------- +\n");
					printf("Total : Rp.%d (+%d)\n\n",5000000+(indeks*1000000), totalpinjam);
					
					getch();
					system("cls");
				}
				else if(input==0){
					system("cls");
					goto menu;
				}
				else{
					goto koperasi;
				}
			}
			if(input==2){
				anggota:
				printf("============ADMINISTRATOR============\n");
				printf("============Manage Anggota===========\n");
				printf("1. Lihat Data\n");
				printf("2. Hapus Data\n");
				printf("3. Ubah Data\n");
				printf("4. Urutkan Data\n");
				printf("5. Cari Data\n\n");
				printf("0. Kembali\n\n");
				printf("Input : ");
				scanf("%d", &input);
				system("cls");
				if(input==1){
					printf("============Daftar Anggota============\n\n");
					tampil();
					printf("Tekan tombol apa saja untuk kembali...");
					getch();
					system("cls");	
					goto anggota;
				}
				else if(input==2){
					hapus:
					//Pengecekan isi data akun
					if(indeks==0){
						printf("========================\n");
						printf("Tidak ada data! Silahkan input data terlebih dahulu!");
						getch();
						system("cls");
						goto anggota;
					}
					//variable admin untuk memasukkan parameter admin pada tampil(int admin);
					
					//fungsi tampil()
					printf("============Hapus Anggota============\n");
					printf("Pilih Data Anggota yang ingin dihapus!\n\n");
					tampil();
					printf("Masukkan angka 0 untuk kembali\n");
					printf("\nInput : ");
					scanf("%d", &input);
					system("cls");
					
					int i=input-1;
					if(input==0){
						system("cls");
						goto menu;
					}
					else if(input<=indeks){
					}
					else{
						printf("======================================\n");
						printf("Tidak ada Data anggota pada nomor %d!",input);
						getch();
						system("cls");
						goto hapus;
					}
					printf("============Hapus Anggota============\n");
					printf("Nama\t\t: %s\n",akun[i].nama);
					printf("Kelamin\t\t: %s\n",akun[i].kelamin);
					printf("Pekerjaan\t: %s\n",akun[i].pekerjaan);
					printf("Nomor HP\t: %s\n",akun[i].nohp);
					printf("-----------------------------\n");
					printf("Tabungan\t: %d\n",akun[i].simpanan);
					printf("Pinjaman\t: %d\n",akun[i].pinjaman);
					printf("-----------------------------\n");
					printf("username\t: %s\n",akun[i].username);
					printf("password\t: %s\n",akun[i].password);
					printf("=====================================\n\n");
					printf("Apakah anda ingin menghapus akun ini?\n");
					printf("1. Hapus\n");
					printf("2. Batal\n\n");
					printf("(Kembali ke menu)\n");
					printf("Input : ");
					scanf("%d", &input);
					system("cls");
					if(input==1){
						hapus(i);
						printf("============Hapus Anggota============\n\n");
						printf("Data telah dihapus.");
						getch();
						system("cls");
					}
					else if(input==2){
						goto hapus;
					}
					else{
						goto anggota;
					}
				}
				else if(input==0){
					system("cls");
					goto menu;
				}
			}
			else if(input==0){
					printf("========================\n\n");
					printf("Anda akan keluar dari akun.\n");
					printf("1.Ya\n");
					printf("2.Batal\n\n");
					printf("Input : ");
					scanf("%d", &input);
	
					if(input==1){
						login=-1;
					}
					else{
						system("cls");
						goto menu;
					}
					system("cls");
				}
		}
		
		else{
			printf("============Koperasi============\n");
			printf("Selamat datang di koperasi Maju Mundur!\n");
			printf("Ada yang bisa saya bantu?\n");
			printf("--------------------------------\n\n");
			printf("1. Cek tabungan\n");
			printf("2. Simpan uang\n");
			printf("3. Pinjam uang\n");
			printf("4. Bayar cicilan\n");
			printf("5. Bayar Simpanan Wajib");
			printf("\n0. Logout\n");
			printf("Input : ");
			scanf("%d", &input);
			system("cls");
			if(input==1){
				printf("============Tabungan============\n\n");
				if(akun[login].simpanan==0){
					printf("Anda tidak memiliki tabungan...");
					getch();
					system("cls");
					goto menu;
				}
				printf("Anda memiliki tabungan sebesar Rp.%d\n\n",akun[login].simpanan);
				printf("Kembali ke menu...");
				getch();
				system("cls");
			}
			else if(input==2){
				printf("============Tabungan============\n\n");
				printf("Masukkan nominal uang : ");
				scanf("%d", &akun[login].simpanan);
				printf("Tabungan telah ditambahkan.\n");
				printf("Uang sejumlah Rp.%d telah ditambahkan ke dalam akun tabungan Anda...", akun[login].simpanan);
				getch();
				system("cls");
			}
			else if(input==3){
				pinjam:
				printf("============Pinjaman============\n\n");
				if(akun[login].pinjaman!=0 || akun[login].cicilan!=0){
					printf("Anda hanya bisa mempunyai 1 pinjaman!");
					getch();
					system("cls");
					goto menu;
				}
				printf("Masukkan nominal uang : ");
				scanf("%d", &pinjam);
				printf("Berapa kali cicilan : ");
				scanf("%d", &cicil);
				if(pinjam==0 || cicil==0){
					goto pinjam;
				}
				system("cls");
				int bunga=(pinjam/cicil)*2/100;
				printf("============Pinjaman============\n\n");
				printf("Anda akan mengirimkan formulir pinjaman untuk :\n");
				printf("*********************************************************************************\n");
				printf("* Pinjaman uang senilai Rp.%d						*\n",pinjam);
				printf("* Dengan total angsuran yang setelah dihitung dengan bunga sebesar Rp.%d\t*\n",pinjam+(bunga*cicil));
				printf("* yang diangsur %d kali per bulan dengan bunga 2%% per bulan.\t\t\t*\n", cicil);
				printf("* Cicilan per bulan yang harus dibayarkan sebesar : Rp.%d\t\t\t*\n",pinjam/cicil+bunga);
				if(pinjam>kas && pinjam!=0){
				printf("*-------------------------------------------------------------------------------*\n");
				printf("* Dikarenakan jumlah pinjaman anda terlalu besar, kemungkinan kami akan     	*\n");
				printf("* meninjau formulir permintaan anda terlebih dahulu.  				*\n");
				}
				printf("*********************************************************************************\n");
				printf("\nApakah anda yakin?\n");
				printf("1. Ya\n");
				printf("2. Tidak\n");
				printf("Input : ");
				scanf("%d", &input);
				system("cls");
				if(input==1){
					if(pinjam<kas){
						akun[login].pinjaman = (pinjam+(bunga*cicil));
						akun[login].cicilan = cicil;					
						akun[login].besarcicilan = pinjam/cicil+bunga;
						kas-=pinjam;
						
						printf("============Pinjaman============\n\n");
						printf("Transaksi berhasil. Anda telah menerima uang pinjaman.\n");
						printf("Silahkan memulai pembayaran cicilan dalam waktu satu bulan.");
						getch();
						system("cls");
					}
					else if(pinjam>kas && pinjam!=0){
						printf("============Pinjaman============\n\n");
						printf("Formulir telah terkirim.\n");
						printf("Kami akan menghubungi anda setelah kami menyetujui pencairan uang pinjaman anda.");
						getch();
						akun[login].cicilan=cicil;
						system("cls");
					}
					else{
						printf("Error!");
						getch();
						system("cls");
					}
				}
				goto menu;
			}
			else if(input==4){
				printf("============Pinjaman============\n\n");
				if(akun[login].pinjaman==0 && akun[login].besarcicilan==0){
					if(akun[login].cicilan>0){
						printf("Anda belum menerima pencairan uang pinjaman.\n");
						printf("Kami akan menghubungi anda setelah kami menyetujui pencairan uang pinjaman anda.");
						getch();
						system("cls");
						goto menu;
					}
					printf("============Pinjaman============\n\n");
					printf("Anda belum mempunyai pinjaman.\n");
					printf("Silahkan membuat/mengirimkan formulir pinjaman terlebih dahulu.");
					getch();
					system("cls");
					goto menu;
				}
				printf("============Pinjaman============\n\n");
				printf("Sisa cicilan anda : Rp.%d\n", akun[login].pinjaman);
				printf("Kurang cicilan : %d kali\n\n", akun[login].cicilan);
				printf("Anda akan membayar sebesar : %d\n\n", akun[login].besarcicilan);
				printf("1. Konfirmasi\n");
				printf("2. Batal\n\n");
				printf("Input : ");
				scanf("%d", &input);
				if (input==1){
					akun[login].pinjaman-=akun[login].besarcicilan;
					akun[login].cicilan-=1;
					//Masuk Kas
					kas+=akun[login].besarcicilan;
					if(akun[login].cicilan==0){
						akun[login].pinjaman=0;
						akun[login].cicilan=0;
						akun[login].besarcicilan=0;
					}
					system("cls");
					printf("============Pinjaman============\n\n");
					printf("Cicilan telah berhasil dibayar.");
					getch();
					system("cls");
				}
				else {
					system("cls");
					goto menu;
				}
			}
			else if(input==5){
				printf("============Simpanan Wajib============\n");
				printf("Anda wajib membayar simpanan wajib mulai bulan depan.");
				getch();
				system("cls");
			}
			else if(input==0){
				printf("============Log Out============\n\n");
				printf("Anda akan keluar dari akun.\n");
				printf("1.Ya\n");
				printf("2.Batal\n\n");
				printf("Input : ");
				scanf("%d", &input);

				if(input==1){
					login=-1;	
				}
				system("cls");
			}
		}
	}
	while(keluar==0);
}
