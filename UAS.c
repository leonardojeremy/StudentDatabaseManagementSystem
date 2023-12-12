#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 10 // jumlah maksimum mahasiswa
#define len 50 // panjang maksium data

typedef struct Node {
  char nama[len];
  char npm[len];
  struct Node *next;
} Node;

void inputData(Node **list, int i) {
  Node *data = (Node *)malloc(sizeof(Node));
  printf("\nMahasiswa %d\n", i + 1);
  printf("Nama : ");
  scanf(" %[^\n]%*c", &data->nama);
  printf("NPM  : ");
  scanf(" %[^\n]%*c", &data->npm);
  data->next = NULL;
  if (*list == NULL) {
    *list = data;
  } else {
    data->next = *list;
    *list = data;
  }
}

void sortNama(Node **head, int n){
	Node *current = *head, *prev = *head;
	Node *nullity = NULL;
	char tmp[max];
	int counter = n;
	while(counter >= 1){
		while(current->next != nullity){
			current = current->next;
			if(strcmp(prev->nama, current->nama) > 0){	//prev > current
				strcpy(tmp, current->nama);
				strcpy(current->nama, prev->nama);
				strcpy(prev->nama, tmp);
				strcpy(tmp, current->npm);
				strcpy(current->npm, prev->npm);
				strcpy(prev->npm, tmp);
			}
			prev = prev->next;
		}
		counter -= 1;
	}		
}

void sortNPM(Node **head, int n){
	Node *current = *head, *prev = *head;
	Node *nullity = NULL;
	char tmp[max];
	int counter = n;
	while(counter >= 1){
		while(current->next != nullity){
			current = current->next;
			if(strcmp(prev->npm, current->npm) > 0){	//prev > current
				strcpy(tmp, current->nama);
				strcpy(current->nama, prev->nama);
				strcpy(prev->nama, tmp);
				strcpy(tmp, current->npm);
				strcpy(current->npm, prev->npm);
				strcpy(prev->npm, tmp);
			}
			prev = prev->next;
		}
		counter -= 1;
	}	
}

void editNama(Node **list, int n, int index[max]) {
  int i, j, k;
  char update[len];
  Node *tmp = *list;
  for (i = 0; i < n; i++) {
    j = index[i];
    for (k = 1; k < j; k++) {
      tmp = tmp->next;
    }
    printf("\nData %s %s\n", tmp->npm, tmp->nama);
    printf("Masukkan nama baru: ");
    scanf(" %[^\n]%*c", update);
    strcpy(tmp->nama, update);
    tmp = *list;
  }
}

void editNPM(Node **list, int n, int index[max]) {
  int i, j, k;
  char update[len];
  Node *tmp = *list;
  for (i = 0; i < n; i++) {
    j = index[i];
    for (k = 1; k < j; k++) {
      tmp = tmp->next;
    }
    printf("\nData %s %s\n", tmp->npm, tmp->nama);
    printf("Masukkan NPM baru: ");
    scanf(" %[^\n]%*c", update);
    strcpy(tmp->npm, update);
    tmp = *list;
  }
}

void searchNama(Node **list, char key[len]) {
  int j, k, a, resultIndex = 0;
  int b = strlen(key);
  Node *temp = *list;
  while (temp != NULL) {
    a = strlen(temp->nama);
    for (j = 0; j <= a - b; j++) {
      for (k = 0; k < b; k++) {
        if (temp->nama[j + k] != key[k])
          break;
      }
      if (k == b) {
        resultIndex++;
        printf("\n%d. %s %s", resultIndex, temp->npm, temp->nama);
      }
    }
    temp = temp->next;
  }
}

void searchNPM(Node **list, char key[len]) {
  int j, k, a, resultIndex = 0;
  int b = strlen(key);
  Node *temp = *list;
  while (temp != NULL) {
    a = strlen(temp->npm);
    for (j = 0; j <= a - b; j++) {
      for (k = 0; k < b; k++) {
        if (temp->npm[j + k] != key[k])
          break;
      }
      if (k == b) {
        resultIndex++;
        printf("\n%d. %s %s", resultIndex, temp->npm, temp->nama);
      }
    }
    temp = temp->next;
  }
}

void printData(Node *list) {
  Node *temp = list;
	
	puts("\nHasil data :");
	if(temp == NULL){
		printf("\nData Kosong\n");
	}
	
	int i = 0;
	while(temp != NULL){
		printf("%d. %s %s\n", i + 1, temp->npm, temp->nama);
		i++;
		temp = temp->next;
	}
}

void bubbleSort(int arr[], int size) {
  int i, j, temp = 0;
  for (i = 0; i < size - 1; i++) {
    for (j = 0; j < size - i - 1; j++) {
      if (arr[j] < arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

void hapusData(Node **list, int pos) {
	Node *current = *list;
	Node *prev = *list;
	if(*list == NULL){
		printf("\nData sudah kosong!\n");
	} else if(pos == 1){
		*list = current->next;
		free(current);
		current = NULL;
	} else {
		while(pos != 1){
			prev = current;
			current = current->next;
			pos--;
		}
		prev->next = current->next;
		free(current);
		current = NULL;
	}
  	printf("Data telah dihapus");
}

void headerPrint() { puts("\t\t<< Aplikasi Managemen Mahasiswa >>"); }

void helpMenu() {
  puts("\t\t\t<< Help Menu >>\n");
  puts("ABOUT PROGRAM");
  puts("Program ini adalah program managemen mahasiswa yang menampung dua "
       "informasi, yaitu:");
  puts("\t1. Nama Mahasiswa");
  puts("\t2. NPM Mahasiswa");
  puts("Program ini mampu melakukan beberapa hal berikut:");
  puts("\t1. Menampung data sesuai input operator");
  puts("\t2. Memanipulasi data yang sudah tersimpan (Menghapus dan mengubah)");
  puts("\t3. Menampilkan data berdasarkan urutan nama atau NPM\n");

  puts("PANDUAN");
  puts("Pada menu utama, anda akan diminta untuk memilih sub-menu. Harap "
       "menekan angka yang sesuai pada keyboard anda.");
  puts("Pada setiap sub-menu, anda mungkin diminta untuk memilih opsi tertentu "
       "kembali. Harap memasukkan opsi yang sesuai.");
  puts("Perhatikan permintaan program. Harap memasukkan input dalam format "
       "yang diminta oleh program.");
  puts("Contoh tepat:\n----------\nJumlah data yang ingin dimasukkan : 10");
  puts("----------\nContoh salah:\n----------");
  puts("Jumlah data yang ingin dimasukkan : Budi");
  puts("----------\n");
  puts("Konfigurasi urutan data yang ditampilkan dapat diubah dalam menu "
       "'Tampilkan Data'\n");
  puts("Tekan apa pun pada keyboard untuk kembali...");
  getch();
}

int main() {
  int i, j, k, n, delTarget[max], option, choice, editChoice[max], sortOpt,
      numData = 0;
  char temp[len];
  Node *list; // Head pertama
 
  char keyword[len];

  list = (Node *)malloc(sizeof(Node));
  if (list == NULL) {
    printf("ERROR: Alokasi memori gagal!\n");
    Sleep(500);
    printf("\nMengeluarkan anda dari program....\n");
    Sleep(1000);
    exit(1);
  }
  
  list = NULL;

  while (1) {
    system("cls");
    headerPrint();
    puts("\t\t\t<< Menu Utama >>\n");
    puts("Selamat datang di menu utama Managemen Mahasiswa!\n");
    puts("1. Input Data");
    puts("2. Hapus Data");
    puts("3. Tampilkan Data");
    puts("4. Search Data");
    puts("5. Edit Data");
    puts("6. Help Menu");
    puts("0. Exit");

    printf("Pilih menu :");
    option = getch() - '0';
    system("cls");
    headerPrint();

    if (option == 0) {
      puts("\t\t\t<< Exit >>\n");
      puts("Terima kasih telah menggunakan program!");
      break;
    } else if (option == 1) {
      puts("\t\t\t<< Menu Input >>\n");
      printf("Jumlah data yang ingin ditambah : ");
      scanf("%d", &n);
      if (n <= 0) {
        puts("Jumlah tidak valid.");
        Sleep(500);
        puts("Mengembalikan anda ke menu...");
        Sleep(1000);
        continue;
      }
      for (i = 0; i < n; i++) {
        inputData(&list, i);
      }
      numData += n;
      printf("\nJumlah data : %d\n", numData);
      printf("Tekan apa pun pada keyboard untuk kembali...");
      getch();
    } else if (option == 2) {
      puts("\t\t\t<< Menu Hapus >>\n");
      printData(list);
      printf("Jumlah data yang ingin dihapus : ");
      scanf("%d", &n);
      if (n <= 0) {
        puts("Jumlah tidak valid.");
        Sleep(500);
        puts("Mengembalikan anda ke menu...");
        Sleep(1000);
        continue;
      }
      for (i = 0; i < n; i++) {
        printf("\nData yang dihapus : ");
        scanf("%d", &delTarget[i]);
      }
      bubbleSort(delTarget, n);
      for(i = 0; i < n; i++){
      	hapusData(&list, delTarget[i]);
      	numData -= 1;
	  }
      printf("\nJumlah data : %d\n", numData);
      printf("Tekan apa pun pada keyboard untuk kembali...");
      getch();
    } else if (option == 3) {
      puts("\t\t\t<< Menu Data >>\n");
      printf("Tampilkan berdasarkan urutan (1. Nama, 2. NPM)...");
      choice = getch() - '0';
      if (choice == 1) {
      	for(i = 0; i < numData-1; i++){
      		sortNama(&list, numData);
		  }
      } else if (choice == 2) {
      	for(i = 0; i < numData-1; i++){
      		sortNPM(&list, numData);
		  }
      } else {
        puts("Pilihan tidak valid.");
        Sleep(500);
        puts("Mengembalikan anda ke menu...");
        Sleep(1000);
        continue;
      }
      printData(list);
      printf("Tekan apa pun pada keyboard untuk kembali...");
      getch();
    } else if (option == 4) {
      puts("\t\t\t<< Menu Pencarian >>\n");
      printf("Search berdasarkan (1. Nama, 2. NPM): ");
      choice = getch() - '0';
      printf("\nMasukkan keyword : ");
      scanf(" %[^\n]%*c", keyword);
      if (choice == 1) {
        printf("\nHasil Pencarian:");
        searchNama(&list, keyword);
      } else if (choice == 2) {
        printf("\nHasil Pencarian:");
        searchNPM(&list, keyword);
      } else {
        puts("Filter pencarian tidak valid.");
        Sleep(500);
        puts("Mengembalikan anda ke menu...");
        Sleep(1000);
      }
      printf("\nTekan apa pun pada keyboard untuk kembali...");
      getch();
    } else if (option == 5) {
      puts("\t\t\t<< Menu Edit >>\n");
      printData(list);
      printf("Jumlah data yang ingin diubah: ");
      scanf("%d", &n);
      if (n <= 0) {
        puts("Jumlah tidak valid.");
        continue;
      }
      for (i = 0; i < n; i++) {
        printf("Data yang ingin diubah: ");
        scanf("%d", &editChoice[i]);
      }
      printf("Edit (1. Nama, 2. NPM): ");
      scanf("%d", &choice);
      if (choice == 1) {
        editNama(&list, n, editChoice);
      } else if (choice == 2) {
        editNPM(&list, n, editChoice);
      } else {
        puts("Pilihan tidak valid.");
        Sleep(500);
        puts("Mengembalikan anda ke menu...");
        Sleep(1000);
        continue;
      }
      printData(list);
      puts("Tekan apa pun pada keyboard untuk kembali...");
      getch();
    } else if (option == 6) {
      helpMenu();
    } else {
      puts("\t\t\t<< Menu Utama >>\n");
      puts("Pilihan tidak valid!");
      Sleep(500);
      puts("Mengembalikan anda ke menu...");
      Sleep(1000);
    }
  }
  free(list);
  return 0;
}
