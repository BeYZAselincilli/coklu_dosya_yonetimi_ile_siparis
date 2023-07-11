/****************************************************************************
**					SAKARYA ÜNÝVERSÝTESÝ
**			BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**				    BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**				PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
****************************************************************************/


#include<windows.h>
#include<fstream>
#include<iostream>
#include<stdio.h>
#include<string>
#include<sstream>
#include<ctime>
#include<clocale>
#include <string.h>
#include <errno.h>


using namespace std;



int urunVarMi = 0; // global degiskenlerimiz
int firmaVarMi = 0;
int secim = 0;
string cevap = " ";

void urunAra(string UrunKodu) { // fonksiyonlarýmýzda urun  var mý diye kontrol edecegimiz fonksiyo
	string urunKodu[200];
	string UrunAdi[200];
	string UrunUretici[200];
	string UrunTeslimTarihi[200];
	string UrunUretimTarihi[200];
	double UrunFiyati[200];
	double UrunOzelFiyati[200];
	double UrunKDV[200];
	int StokUrun[200];
	int i = 0;
	ifstream urunDosyaOku("Urun.txt");
	while (urunDosyaOku >> urunKodu[i] >> UrunAdi[i] >> UrunUretici[i] >> UrunTeslimTarihi[i] >> UrunUretimTarihi[i] >> UrunFiyati[i] // urun kayýtlarýmýzý okuyoruz eger varsa urunvarmý'ya 1 atýyoruz
		>> UrunOzelFiyati[i] >> UrunKDV[i] >> StokUrun[i]) {
		if (UrunKodu == urunKodu[i])
		{
			urunVarMi = 1;
		}
		i++;

	}
	urunDosyaOku.close();
}
void firmaAra(string FirmaKodu) {
											// fonksiyonlarýmýzda firma  var mý diye kontrol edecegimiz fonksiyon
	string firmaKodu[200];
	string firmaAdi[200];
	string firmaTelefon[200];
	string firmaSorumlusu[200];
	string musteriKategorisi[200];
	string firmaAdresi[200];
	int i = 0;
	ifstream dosyaOku("Cari.txt");

	while (dosyaOku >> firmaKodu[i] >> firmaAdi[i] >> firmaTelefon[i] >> firmaSorumlusu[i] >> musteriKategorisi[i] >> firmaAdresi[i]) {// firma kayýtlarýmýzý okuyoruz eger varsa firmavarmý'ya 1 atýyoruz

		if (dosyaOku.eof())//dosya sonuna gelindiyse
		{
			break;
		}
		if (FirmaKodu == firmaKodu[i])
		{
			firmaVarMi = 1;
		}

		i++;

	}
	dosyaOku.close();
}
void UrunEkle(string UrunKodu) {
	ofstream urunDosyaYaz("Urun.txt", ios::app); // APP MODUNDA DOSYAMIZIN SONUNA KULLANICIDAN ALDIGIMIZ BÝLGÝLERÝ URUN.TXT'YE YAZIYORUZ
	string UrunEkleAdet;
	string UrunEkleKod;
	string UrunEkleAd;
	string UrunEkleUretici;
	string UrunEkleTeslim;
	string UrunEkleUretim;
	double UrunFiyat;
	double UrunOzelFiyat;
	double UrunKDV;
	int UrunStokAdet;

	cout << "Urunun adini giriniz..." << endl;
	cin >> UrunEkleAd;
	cout << "Lutfen ekleyeceginiz urunun ureticisini giriniz..." << endl;
	cin >> UrunEkleUretici;
	cout << "Lutfen ekleyeceginiz urunun temin suresini giriniz..." << endl;
	cin >> UrunEkleTeslim;
	cout << "Lutfen ekleyeceginiz urunun uretim tarihi giriniz..." << endl;
	cin >> UrunEkleUretim;
	cout << "Lutfen ekleyeceginiz urunun fiyatini giriniz..." << endl;
	cin >> UrunFiyat;
	cout << "Lutfen ekleyeceginiz urunun özel fiyatini giriniz..." << endl;
	cin >> UrunOzelFiyat;
	cout << "Lutfen ekleyeceginiz urunun kdv'sini giriniz..." << endl;
	cin >> UrunKDV;
	cout << "Lutfen ekleyeceginiz urunun stok adeti giriniz..." << endl;
	cin >> UrunStokAdet;
	urunDosyaYaz << UrunEkleKod << " " << UrunEkleAd << " " << UrunEkleUretici << " "
		<< UrunEkleTeslim << " " << UrunEkleUretim << " " << UrunFiyat << " " << UrunOzelFiyat << " " << UrunKDV << " "
		<< UrunStokAdet << endl;
	urunDosyaYaz.close();

	cout << "Urununuz basariyla kaydedilmistir.....;" << endl;
}
void SeciliUrunEkranaBastir() { // kullanýcýnýn istedigi urunu ekrana bastýran fonksiyon

	string urun;
	cout << "Aramak istediginiz urun kodunu giriniz..:";
	cin >> urun;
	urunAra(urun);
	if (urunVarMi != 1) // urunvarmý fonksiyondan 1'e atanmazsa boyle bir urunumuz yok demektir.
	{
		cout << "Boyle bir urunumuz yoktur... \n";
	}
	else // ELSE BLOGU CALISIRSA BOYLE URUN VAR DEMEKTIR
	{
		string UrunKodu[200];
		string UrunAdi[200];
		string UrunUreticisi[200];
		string UrunTeslimTarihi[200];
		string UrunUretimTarihi[200];
		double UrunFiyati[200];
		double UrunFiyatiOzel1[200];
		double UrunKDV[200];
		int UrunStok[200];

		int i = 0;

		ifstream UrunDosyaOku("Urun.txt");

		while (UrunDosyaOku >> UrunKodu[i] >> UrunAdi[i] >> UrunUreticisi[i] >> UrunTeslimTarihi[i] >> UrunUretimTarihi[i] >> UrunFiyati[i]
			>> UrunFiyatiOzel1[i] >> UrunKDV[i] >> UrunStok[i]) {
			// DOSYAMIZDAN KAYITLARIMIZI INDEXLERINE GORE OKUYORUZ

			if (urun == UrunKodu[i]) // EGER INPUT DEGERI INDEX DEGERIMIZE ESÝTSE EKRANA BASTIRIYORUZ
			{
				cout << "Urun Kodu..:" << UrunKodu[i] << endl;
				cout << "Urun Adi..:" << UrunAdi[i] << endl;
				cout << "Urun Ureticisi..:" << UrunUreticisi[i] << endl;
				cout << "Urun Teslim Tarihi..:" << UrunTeslimTarihi[i] << endl;
				cout << "Urun Uretim Tarihi..:" << UrunUretimTarihi[i] << endl;
				cout << "Urun Fiyati..:" << UrunFiyati[i] << endl;
				cout << "Urun Fiyati Özel..:" << UrunFiyatiOzel1[i] << endl;
				cout << "Urun KDV..:" << UrunKDV[i] << endl;
				cout << "Urun Stok Adet..:" << UrunStok[i] << endl;

			}
			i++;
		}
		UrunDosyaOku.close();
	}

}
void UrunListeleme() { // tum urunlerimizi ekrana bastýran fonksiyonummuz
	ifstream UrunDosyaOku("Urun.txt"); // DOSYAMIZI OKUYORUZ
	string UrunKodu[200];
	string UrunAdi[200];
	string UrunUreticisi[200];
	string UrunTeslimTarihi[200];
	string UrunUretimTarihi[200];
	double UrunFiyati[200];
	double UrunFiyatiOzel1[200];
	double UrunKDV[200];
	int UrunStok[200];
	int i = 0;
	while (UrunDosyaOku >> UrunKodu[i] >> UrunAdi[i] >> UrunUreticisi[i] >> UrunTeslimTarihi[i] >> UrunUretimTarihi[i] >> UrunFiyati[i]
		>> UrunFiyatiOzel1[i] >> UrunKDV[i] >> UrunStok[i]) {

		i++;
	}
	system("cls");
	for (int k = 0; k < i; k++)
	{
		cout << "Urun Kodu..:" << UrunKodu[k] << endl; // DOSYAMIZDAN VERÝLERÝMÝZÝ OKURKEN EKRANA BASTIRARAK LÝSTELEME ÝÞLEMÝNÝ YAPIYORUZ
		cout << "Urun Adi..:" << UrunAdi[k] << endl;
		cout << "Urun Ureticisi..:" << UrunUreticisi[k] << endl;
		cout << "Urun Teslim Tarihi..:" << UrunTeslimTarihi[k] << endl;
		cout << "Urun Uretim Tarihi..:" << UrunUretimTarihi[k] << endl;
		cout << "Urun Fiyati..:" << UrunFiyati[k] << endl;
		cout << "Urun Fiyati Ozel..:" << UrunFiyatiOzel1[k] << endl;
		cout << "Urun KDV..:" << UrunKDV[k] << endl;
		cout << "Urun Stok Adet..:" << UrunStok[k] << endl;
		cout << endl <<  endl;
	}

	UrunDosyaOku.close();
}
void UrunGuncelleme() {
	string urunKoduInput;
	cout << "Guncellenecek urun kodunu giriniz... \n"; // KULLANICIDAN GUNCELLEYECEGÝ URUNUN KODUNU  ALIYORUZ
	cin >> urunKoduInput;

	string UrunKodu[200];
	string UrunAdi[200];
	string UrunUreticisi[200];
	string UrunTeslimTarihi[200];
	string UrunUretimTarihi[200];
	double UrunFiyati[200];
	double UrunFiyatiOzel1[200];
	double UrunKDV[200];
	int UrunStok[200];
	int i = 0;
	int j = 0;
	urunAra(urunKoduInput);
	if (urunVarMi == 1) // EGER URUN ARA 1 DÖNDÜRÜRSE BOYLE BÝR KAYDIMIZ VAR DEMEKTÝR
	{
		ifstream dosyaOku("Urun.txt");
		ofstream urunDosyaYaz("urun.tmp"); // TEMP DOSYASI OLUSTURUYORUZ CUNKU KAYITLARIMIZI TEMP'E ATIP SONRADAN ISMINI DEGÝSTÝRECEGÝZ
		while (dosyaOku >> UrunKodu[i] >> UrunAdi[i] >> UrunUreticisi[i] >> UrunTeslimTarihi[i] >> UrunUretimTarihi[i] >> UrunFiyati[i]
			>> UrunFiyatiOzel1[i] >> UrunKDV[i] >> UrunStok[i]) { // TUM VERÝLERÝMÝZÝ DÝZÝLERÝMÝZE ALDIK

			if (dosyaOku.eof())//dosya sonuna gelindiyse
			{
				break;
			}
			if (urunKoduInput == UrunKodu[i]) // YENÝ BÝLGÝLERÝ ALIYORUZ
			{
				cout << "Lutfen yeni degerlerinizi giriniz.." << endl;
				cout << "Urunun adini giriniz..." << endl;
				cin >> UrunAdi[i];
				cout << "Lutfen  urunun ureticisini giriniz..." << endl;
				cin >> UrunUreticisi[i];
				cout << "Lutfen  urunun temin suresini giriniz..." << endl;
				cin >> UrunTeslimTarihi[i];
				cout << "Lutfen  urunun uretim tarihi giriniz..." << endl;
				cin >> UrunUretimTarihi[i];
				cout << "Lutfen  urunun fiyatini giriniz..." << endl;
				cin >> UrunFiyati[i];
				cout << "Lutfen  urunun özel fiyatini giriniz..." << endl;
				cin >> UrunFiyatiOzel1[i];
				cout << "Lutfen  urunun kdv'sini giriniz..." << endl;
				cin >> UrunKDV[i];
				cout << "Lutfen  urunun stok adeti giriniz..." << endl;
				cin >> UrunStok[i];
				urunDosyaYaz << UrunKodu[i] << " " << UrunAdi[i] << " " << UrunUreticisi[i] << " "
					<< UrunTeslimTarihi[i] << " " << UrunUretimTarihi[i] << " " << UrunFiyati[i] << " " << UrunFiyatiOzel1[i] << " " << UrunKDV[i] << " "
					<< UrunStok[i] << endl;

			}
			else // ESLESMEYEN DEGERLERÝ YAZDIRIYORUZ
			{
				urunDosyaYaz << UrunKodu[i] << " " << UrunAdi[i] << " " << UrunUreticisi[i] << " "
					<< UrunTeslimTarihi[i] << " " << UrunUretimTarihi[i] << " " << UrunFiyati[i] << " " << UrunFiyatiOzel1[i] << " " << UrunKDV[i] << " "
					<< UrunStok[i] << endl;

			}

			i++;

		}

		dosyaOku.close();
		urunDosyaYaz.close();
		remove("Urun.txt");

		int temp = rename("Urun.tmp", "Urun.txt"); // URUN.TMP'Ý TXT'YE CEVÝRÝP ESKÝ URUN.TXT'YÝ SÝLÝYORUZ

	}

}
void UrunSil() {
	string urunKoduInput;
	cout << "Silenecek urun kodunu giriniz... \n"; // KULLANICIDAN SÝLECEGÝ URUNUN KODUNU  ALIYORUZ
	cin >> urunKoduInput;

	string UrunKodu[200];
	string UrunAdi[200];
	string UrunUreticisi[200];
	string UrunTeslimTarihi[200];
	string UrunUretimTarihi[200];
	double UrunFiyati[200];
	double UrunFiyatiOzel1[200];
	double UrunKDV[200];
	int UrunStok[200];
	int i = 0;
	int j = 0;
	urunAra(urunKoduInput);
	if (urunVarMi == 1) // EGER URUN ARA 1 DÖNDÜRÜRSE BOYLE BÝR KAYDIMIZ VAR DEMEKTÝR
	{
		ifstream dosyaOku("Urun.txt");
		ofstream urunDosyaYaz("urun.tmp");
		while (dosyaOku >> UrunKodu[i] >> UrunAdi[i] >> UrunUreticisi[i] >> UrunTeslimTarihi[i] >> UrunUretimTarihi[i] >> UrunFiyati[i]
			>> UrunFiyatiOzel1[i] >> UrunKDV[i] >> UrunStok[i]) { // TUM VERÝLERÝMÝZÝ DÝZÝLERÝMÝZE ALDIK

			if (dosyaOku.eof())//dosya sonuna gelindiyse
			{
				break;
			}
			if (urunKoduInput != UrunKodu[i])
			{
				urunDosyaYaz << UrunKodu[i] << " " << UrunAdi[i] << " " << UrunUreticisi[i] << " "
					<< UrunTeslimTarihi[i] << " " << UrunUretimTarihi[i] << " " << UrunFiyati[i] << " " << UrunFiyatiOzel1[i] << " " << UrunKDV[i] << " "
					<< UrunStok[i] << endl;

			}
			i++;

		}
		dosyaOku.close();
		urunDosyaYaz.close();
		remove("Urun.txt");
		int value = rename("Urun.tmp", "Urun.txt");
	}

}
void MusteriEkle() {
	string FirmaKod, FirmaAdi, FirmaTelefon, FirmaSorumlusu, MusteriKategori, FirmaAdres;

	cout << "Ekleyeceginiz firmanýn kodunu giriniz...\n"; // FÝRMA EKLEMEK ÝCÝN INPUT ALIYORUZ
	cin >> FirmaKod;
	firmaAra(FirmaKod);
	if (firmaVarMi != 1) // FÝRMAVARMI 1 DEGÝLSE BOYLE KAYDIMIZ YOK DEMEKTÝR
	{
		ofstream dosyaYaz("Cari.txt", ios::app); // EGER KAYDIMIZ YOKSA APP MODUNDA DOSYAMIZIN SONUNA KULLANICIDAN ALDIGIMIZ DEGERLERÝ YAZDIRIYORUZ
		cout << "Lutfen firma adi giriniz..." << endl;
		cin >> FirmaAdi;
		cout << "Lutfen firma telefonunu giriniz..." << endl;
		cin >> FirmaTelefon;
		cout << "Lutfen firma sorumlusunu giriniz..." << endl;
		cin >> FirmaSorumlusu;
		cout << "Lutfen musteri kategorisini giriniz..." << endl;
		cin >> MusteriKategori;
		cout << "Lutfen firma adresini giriniz..." << endl;
		cin >> FirmaAdres;

		dosyaYaz << FirmaKod << " " << FirmaAdi << " " << FirmaTelefon << " " << FirmaSorumlusu << " " << MusteriKategori << " " << FirmaAdres << endl;

	}
	else
	{
		cout << "Boyle bir firma bulunmaktadir.." << endl;
	}





}
void SeciliMusteriyiEkranaBastir() { // KULLANICININ ISTEDÝGÝ FÝRMAYI BASTIRIYORUZ
	string musteri;
	cout << "Aramak istediginiz musteri kodunu giriniz..:";
	cin >> musteri;
	firmaAra(musteri);
	if (firmaVarMi != 1)
	{
		cout << "Boyle bir musterimiz yoktur... \n";
	}
	else // ELSE BLOGU CALISIRSA BOYLE MUSTERÝ VAR DEMEKTIR
	{
		string firmaKodu[200];
		string firmaAdi[200];
		string firmaTelefon[200];
		string firmaSorumlusu[200];
		string musteriKategorisi[200];
		string firmaAdresi[200];

		int i = 0;

		ifstream UrunDosyaOku("Cari.txt");

		while (UrunDosyaOku >> firmaKodu[i] >> firmaAdi[i] >> firmaTelefon[i] >> firmaSorumlusu[i] >> musteriKategorisi[i] >> firmaAdresi[i]) {
			// DOSYAMIZDAN KAYITLARIMIZI INDEXLERINE GORE OKUYORUZ

			if (musteri == firmaKodu[i]) // EGER INPUT DEGERI INDEX DEGERIMIZE ESÝTSE EKRANA BASTIRIYORUZ
			{
				cout << "Firma Kodu..:" << firmaKodu[i] << endl;
				cout << "Firma Adi..:" << firmaAdi[i] << endl;
				cout << "Firma Telefon Numarasi..:" << firmaTelefon[i] << endl;
				cout << "Firma Sorumlusu..:" << firmaSorumlusu[i] << endl;
				cout << "Musteri Kategorisi..:" << musteriKategorisi[i] << endl;
				cout << "Firma Adresi..:" << firmaAdresi[i] << endl << endl;

			}
			i++;
		}
		UrunDosyaOku.close();
	}
}
void MusteriListeleme() {
	ifstream UrunDosyaOku("Cari.txt"); // DOSYAMIZI OKUYORUZ
	string firmaKodu[200];
	string firmaAdi[200];
	string firmaTelefon[200];
	string firmaSorumlusu[200];
	string musteriKategorisi[200];
	string firmaAdresi[200];
	int i = 0;
	while (UrunDosyaOku >> firmaKodu[i] >> firmaAdi[i] >> firmaTelefon[i] >> firmaSorumlusu[i] >> musteriKategorisi[i] >> firmaAdresi[i]) {

		i++;
	}
	system("cls");
	for (int k = 0; k < i; k++)
	{
		cout << "Firma Kodu..:" << firmaKodu[k] << endl; // DOSYAMIZDAN VERÝLERÝMÝZÝ OKURKEN EKRANA BASTIRARAK LÝSTELEME ÝÞLEMÝNÝ YAPIYORUZ
		cout << "Firma Adi..:" << firmaAdi[k] << endl;
		cout << "Firma Telefonu..:" << firmaTelefon[k] << endl;
		cout << "Firma Sorumlusu..:" << firmaSorumlusu[k] << endl;
		cout << "Musteri Kategorisi..:" << musteriKategorisi[k] << endl;
		cout << "Firma  Adresi..:" << firmaAdresi[k] << endl;

		cout << endl << endl << endl;
	}

	UrunDosyaOku.close();
}
void MusteriGuncelleme() {
	string firmaKoduInput;
	cout << "Guncellenecek firmanýn kodunu giriniz... \n"; // KULLANICIDAN GUNCELLEYECEGÝ FIRMANIN KODUNU  ALIYORUZ
	cin >> firmaKoduInput;

	string firmaKodu[200];
	string firmaAdi[200];
	string firmaTelefon[200];
	string firmaSorumlusu[200];
	string musteriKategorisi[200];
	string firmaAdresi[200];
	int i = 0;

	firmaAra(firmaKoduInput);
	if (firmaVarMi == 1) // EGER FIRMA ARA 1 DÖNDÜRÜRSE BOYLE BÝR KAYDIMIZ VAR DEMEKTÝR
	{
		ifstream dosyaOku("Cari.txt");
		ofstream firmaDosyaYaz("Cari.tmp"); // TEMP DOSYAMIZI ACIYORUZ
		while (dosyaOku >> firmaKodu[i] >> firmaAdi[i] >> firmaTelefon[i] >> firmaSorumlusu[i] >> musteriKategorisi[i] >> firmaAdresi[i]) { // TUM VERÝLERÝMÝZÝ DÝZÝLERÝMÝZE ALDIK

			if (dosyaOku.eof())//dosya sonuna gelindiyse
			{
				break;
			}
			if (firmaKoduInput == firmaKodu[i]) // YENÝ DEGERLERÝMÝZÝ ALIYORUZ
			{
				cout << "Lutfen yeni degerlerinizi giriniz.." << endl;
				cout << "Firmanýn adini giriniz..." << endl;
				cin >> firmaAdi[i];
				cout << "Lutfen  firmanýn telefonunu giriniz..." << endl;
				cin >> firmaTelefon[i];
				cout << "Lutfen  firmanýn sorumlusunu giriniz..." << endl;
				cin >> firmaSorumlusu[i];
				cout << "Lutfen  musterinin kategorisini giriniz..." << endl;
				cin >> musteriKategorisi[i];
				cout << "Lutfen  firmanýn adresini giriniz..." << endl;
				cin >> firmaAdresi[i];
				firmaDosyaYaz << firmaKodu[i] << " " << firmaAdi[i] << " " << firmaTelefon[i] << " " << firmaSorumlusu[i] << " " << musteriKategorisi[i] << " " << firmaAdresi[i] << endl;
			}
			else
			{
				firmaDosyaYaz << firmaKodu[i] << " " << firmaAdi[i] << " " << firmaTelefon[i] << " " << firmaSorumlusu[i] << " " << musteriKategorisi[i] << " " << firmaAdresi[i] << endl;
			}

			i++;

		}

		dosyaOku.close();
		firmaDosyaYaz.close();
		remove("Cari.txt");

		int temp = rename("Cari.tmp", "Cari.txt"); // DOSYA ÝSÝMLERÝMÝ DEGÝSTÝRÝYORUZ

	}
	else
	{
		cout << "Boyle bir firma/musteri bulunamamistir..." << endl;
	}
}
void MusteriSil() {
	string firmaKoduInput;
	cout << "Silenecek firmanýn kodunu giriniz... \n"; // KULLANICIDAN GUNCELLEYECEGÝ FIRMANIN KODUNU  ALIYORUZ
	cin >> firmaKoduInput;

	string firmaKodu[200];
	string firmaAdi[200];
	string firmaTelefon[200];
	string firmaSorumlusu[200];
	string musteriKategorisi[200];
	string firmaAdresi[200];
	int i = 0;

	firmaAra(firmaKoduInput);
	if (firmaVarMi == 1) // EGER FIRMA ARA 1 DÖNDÜRÜRSE BOYLE BÝR KAYDIMIZ VAR DEMEKTÝR
	{
		ifstream dosyaOku("Cari.txt");
		ofstream firmaDosyaYaz("Cari.tmp");
		while (dosyaOku >> firmaKodu[i] >> firmaAdi[i] >> firmaTelefon[i] >> firmaSorumlusu[i] >> musteriKategorisi[i] >> firmaAdresi[i]) { // TUM VERÝLERÝMÝZÝ DÝZÝLERÝMÝZE ALDIK

			if (dosyaOku.eof())//dosya sonuna gelindiyse
			{
				break;
			}
			if (firmaKoduInput != firmaKodu[i])
			{
				firmaDosyaYaz << firmaKodu[i] << " " << firmaAdi[i] << " " << firmaTelefon[i] << " " << firmaSorumlusu[i] << " " << musteriKategorisi[i] << " " << firmaAdresi[i] << endl;
			}

			i++;

		}

		dosyaOku.close();
		firmaDosyaYaz.close();
		remove("Cari.txt");

		int temp = rename("Cari.tmp", "Cari.txt"); // DOSYA TMP'Ý DEGÝSTÝRÝYORUZ
		cout << "Musteri silinmistir.." << endl;

	}
	else
	{
		cout << "Boyle bir firma/musteri bulunamamistir..." << endl;
	}

}
void SiparisOlustur() {
	string FirmaKodu;
	cout << "Siparisini vermek istediginiz firmanin kodunu giriniz...\n";
	cin >> FirmaKodu; // SÝPARÝS FÝRMA KODUNU INPUT ALIYORUZ
	string firmaKodu[200];
	string firmaAdi[200];
	string firmaTelefon[200];
	string firmaSorumlusu[200];
	string musteriKategorisi;
	string firmaAdresi[200];
	double satinAlinanAdet = 0;
	string siparisTarihi;
	double siparisTutari;
	string siparisiAlan;
	int i = 0;

	ifstream dosyaOku("Cari.txt");

	while (dosyaOku >> firmaKodu[i] >> firmaAdi[i] >> firmaTelefon[i] >> firmaSorumlusu[i] >> musteriKategorisi >> firmaAdresi[i]) {

		if (FirmaKodu == firmaKodu[i]) // EGER GÝRÝLEN FÝRMA KODU KAYITLIYSA SÝPARÝS ALIYORUZ
		{
			string urunSiparisKod;
			firmaVarMi = 1; // FÝRMA VAR MI 1 ATANDI

			cout << "Lutfen siparis vermek istediginiz urunun kodunu giriniz...";
			cin >> urunSiparisKod;

			ifstream dosyaOku2("Urun.txt");
			string urunKodu[200];
			string urunAdi[200];
			string urunUreticisi[200];
			string urunTeslimTarihi[200];
			string urunUretimTarihi[200];
			double urunFiyati[200];
			double urunFiyatiOzel[200];
			double urunKDV[200];
			int urunStok[200];

			int k = 0;
			string musteriOzel = "genel";


			while (dosyaOku2 >> urunKodu[k] >> urunAdi[k] >> urunUreticisi[k] >> urunTeslimTarihi[k] >> urunUretimTarihi[k] >> urunFiyati[k]
				>> urunFiyatiOzel[k] >> urunKDV[k] >> urunStok[k]) {

				if (urunSiparisKod == urunKodu[k] && urunStok[k] != 0) // EGER KULLANICININ GÝRDÝGÝ URUN KAYITLI ÝSE VE STOÐU VARSA SÝPARÝS BÝLGÝLERÝNÝ ALIYORUZ
				{
					cout << "Kac tane satin almak istiyorsunuz..:";
					cin >> satinAlinanAdet;
					cout << "Siparis tarihini giriniz...:";
					cin >> siparisTarihi;
					cout << "Siparisi alan kisinin gorevlinin adini giriniz..:";
					cin >> siparisiAlan;
					urunVarMi = 1; // SÝPARÝS BÝLGÝLERÝNÝ ALDIK VE urunVarMi 1 ATADIK

					if (musteriKategorisi == "genel") // MUSTERÝ KATEGORÝSÝNE GORE OZEL FÝYATLANDIRMA YAPIYORUZ
					{
						siparisTutari = urunKDV[k] * urunFiyatiOzel[k] * satinAlinanAdet;
					}
					else if (musteriKategorisi == "ozel")
					{
						siparisTutari = urunKDV[k] * urunFiyati[k] * satinAlinanAdet;
					}
					else
					{
						exit(0);
					}
					urunStok[k]--; // STOK DUSUYORUZ

					ofstream dosyaYaz1("xyz.txt", ios::app);
					dosyaYaz1 << urunKodu[k] << " " << satinAlinanAdet << " " << firmaKodu[i] << endl;
					dosyaYaz1.close();
					ofstream dosyaYaz2("Siparis.txt", ios::app); // DOSYAMIZIN SONUNA VERÝLERÝMÝZÝ YAZIYORUZ
					dosyaYaz2 << firmaKodu[i] << " " << siparisTarihi << " " << siparisTutari << " " << musteriKategorisi << " " << siparisiAlan << " " << urunKodu[k] << endl;
					dosyaYaz2.close();

				}


				k++;

			}

			dosyaOku2.close();

		}
		i++;
	}

	if (firmaVarMi == 1 && urunVarMi == 1) // IKISI DE TRUE DONERSE SIPARISIMIZI ALMISIZ DEMEKTÝR
	{
		cout << "Siparisiniz alinmistir..." << endl;
	}
	else
	{
		cout << "Siparis alinma süresince bir hata meydana geldi!." << endl;
	}

	dosyaOku.close();

}
void SiparisAra() {
	string FirmaKod, UrunKod;
	cout << "Aramak istediginiz siparisinizin firmasini giriniz ";
	cin >> FirmaKod;
	cout << "Aramak istediginiz siparisinizin urun kodunu giriniz..:";
	cin >> UrunKod;
	firmaAra(FirmaKod); // FÝRMA VE URUN ARA FONKSÝYONLARINI CAGIRIYORUZ
	urunAra(UrunKod);

	if (firmaVarMi == 1 && urunVarMi == 1) // FÝRMA VE URUN KODU 1 DONERSE DEMEK KÝ KAYDIMIZ VAR DEMEKTÝR
	{
		string firmaKodu[200];
		string siparisTarihi[200];
		string siparisTutari[200];
		string siparisiAlan[200];
		string siparisListesiDosyasi;
		string urunKodu[200];
		string urunKodu2[200];
		string urunAdedi[200];

		int i = 0;
		int j = 0;

		string firmaKodu2[200];
		ifstream dosyaOku("Siparis.txt");
		while (dosyaOku >> firmaKodu[i] >> siparisTarihi[i] >> siparisTutari[i] >> siparisListesiDosyasi >> siparisiAlan[i] >> urunKodu2[i])
		{

			if (FirmaKod == firmaKodu[i] && urunKodu2[i] == UrunKod) // GÝRÝLEN KAYIT VE INDEX ESLESÝRSE SIPARIS LISTELIYORUZ
			{

				ifstream dosyaOku2("xyz.txt");
				while (dosyaOku2 >> urunKodu[j] >> urunAdedi[j] >> firmaKodu2[j])
				{
					if (UrunKod == urunKodu[j] && firmaKodu2[j] == FirmaKod) // EGER URUN KODU VE FIRMA KODU ESLESÝRSE EKRANA YAZDIRIYORUZ
					{
						cout << endl << "Siparisinizin firmasi....:" << firmaKodu[i] << endl;
						cout << "Siparisinizin tarihi....:" << siparisTarihi[i] << endl;
						cout << "Siparisinizin tutari....:" << siparisTutari[i] << endl;
						cout << "Siparisinizi alan kisi....:" << siparisiAlan[i] << endl;
						cout << "Siparisinizin urun kodu....:" << urunKodu[j] << endl;
						cout << "Siparisinizin urun adedi....:" << urunAdedi[j] << endl;
						break;
					}
					j++;
				}
				dosyaOku2.close();
			}

			i++;

		}
		dosyaOku.close();
	}
	else
	{
		cout << "Maalesef boyle bir siparis bulunmamaktadir...:";
	}
}
void SiparisSil() {
	string FirmaKod, UrunKod;
	cout << "Lutfen silmek istediginiz siparisin firma kodunu soyleyin..:";
	cin >> FirmaKod;
	cout << "Lutfen silmek istediginiz siparisin urun kodunu giriniz..:";
	cin >> UrunKod;
	firmaAra(FirmaKod);
	urunAra(UrunKod);
	if (firmaVarMi == 1 && urunVarMi == 1) // EGER SILINMEK ISTENILEN KAYIT VAR ISE IF BLOGU ICINE GIRIYOR
	{
		string firmaKodu[200];
		string siparisTarihi[200];
		string siparisTutari[200];
		string siparisiAlan[200];
		string siparisListesiDosyasi;
		string urunKodu[200];
		string urunKodu2[200];
		string urunAdedi[200];
		ifstream dosyaOku("Siparis.txt");
		ifstream dosyaOku2("xyz.txt");
		int i = 0;
		int j = 0;
		string firmaKodTemp[200];
		while (dosyaOku >> firmaKodu[i] >> siparisTarihi[i] >> siparisTutari[i] >> siparisListesiDosyasi >> siparisiAlan[i] >> urunKodu2[i])
		{
			if (dosyaOku.eof())
			{
				break;
			}
			i++;
		}
		i = 0;
		dosyaOku.close();
		while (dosyaOku2 >> urunKodu[i] >> urunAdedi[i] >> firmaKodTemp[i]) // DOSYALARIMIZDAN KAYITLARIMIZI ALDIK
		{
			if (dosyaOku2.eof())
			{
				break;
			}
			i++;
		}
		dosyaOku2.close();
		ofstream dosyaYaz("Siparis.tmp");
		ofstream dosyaYaz2("xyz.tmp");

		if (dosyaYaz.is_open() && dosyaYaz2.is_open()) // DOSYALAR BASARIYLA ACILDIYSA
		{
			for (int k = 0; k <= i; k++) // INDEX SAYISI KADAR DONDURUYORUZ
			{
				if (dosyaYaz.eof())
				{
					break;
				}
				if (FirmaKod == firmaKodu[k] && UrunKod == urunKodu2[k]) // FIRMA KODU VE URUN KODU ESLESÝRSE DIGER FOR'A GÝRÝYORUZ
				{
					for (int t = 0; t <= i; t++)
					{
						if (dosyaYaz2.eof())
						{
							break;
						}
						if (UrunKod == urunKodu[t] && FirmaKod == firmaKodTemp[t]) // EGER BURDA DA URUNKODU VE FIRMAKODUTEMP ESLESÝRSE ISTEDÝGÝMÝZ KAYITTIR VE DOSYAYA YAZDIRMIYORUZ
						{

						}
						else // DIGER KAYITLARIMIZI YAZDIRIYORUZ
						{
							dosyaYaz2 << urunKodu[t] << " " << urunAdedi[t] << " " << firmaKodTemp[t] << endl;
						}
					}
				}
				else// DIGER KAYITLARIMIZI YAZDIRIYORUZ
				{
					dosyaYaz << firmaKodu[k] << " " << siparisTarihi[k] << " " << siparisTutari[k] << " " << siparisListesiDosyasi << " " << siparisiAlan[k] << " " << urunKodu2[k] << endl;
				}
			}
		}

		dosyaYaz.close();
		dosyaYaz2.close();
		remove("Siparis.txt");
		remove("xyz.txt");
		int temp = rename("Siparis.tmp", "Siparis.txt"); // DOSYALARIMIZI DEGÝSTÝRÝYORUZ
		int temp2 = rename("xyz.tmp", "xyz.txt");

		cout << "Siparisiniz silinmistir..\n";

	}
	else
	{
		cout << "Boyle bir urun&firma bulunamamaktadir..\n";
	}
}
void SiparisDuzeltme() {
	string FirmaKod, UrunKod;
	cout << "Lutfen duzeltmek istediginiz siparisin firma kodunu soyleyin..:";
	cin >> FirmaKod;
	cout << "Lutfen duzeltmek istediginiz siparisin urun kodunu giriniz..:";
	cin >> UrunKod;
	firmaAra(FirmaKod);
	urunAra(UrunKod);
	if (firmaVarMi == 1 && urunVarMi == 1) // EGER SILINMEK ISTENILEN KAYIT VAR ISE IF BLOGU ICINE GIRIYOR
	{
		string firmaKodu[200];
		string siparisTarihi[200];
		string siparisTutari[200];
		string siparisiAlan[200];
		string siparisListesiDosyasi;
		string urunKodu[200];
		string urunKodu2[200];
		string urunAdedi[200];
		ifstream dosyaOku("Siparis.txt");
		ifstream dosyaOku2("xyz.txt");
		int i = 0;
		int j = 0;
		string firmaKodTemp[200];
		while (dosyaOku >> firmaKodu[i] >> siparisTarihi[i] >> siparisTutari[i] >> siparisListesiDosyasi >> siparisiAlan[i] >> urunKodu2[i])
		{
			if (dosyaOku.eof())
			{
				break;
			}
			i++;
		}
		i = 0;
		dosyaOku.close();
		while (dosyaOku2 >> urunKodu[i] >> urunAdedi[i] >> firmaKodTemp[i]) // DOSYA KAYITLARIMIZI OKUYORYZ
		{
			if (dosyaOku2.eof())
			{
				break;
			}
			i++;
		}
		dosyaOku2.close();
		ofstream dosyaYaz("Siparis.tmp");
		ofstream dosyaYaz2("xyz.tmp");

		if (dosyaYaz.is_open() && dosyaYaz2.is_open())
		{
			for (int k = 0; k < i; k++)
			{
				if (dosyaYaz.eof())
				{
					break;
				}
				if (FirmaKod == firmaKodu[k] && UrunKod == urunKodu2[k])
				{
					for (int t = 0; t <= i; t++)
					{
						if (dosyaYaz2.eof())
						{
							break;
						}
						if (UrunKod == urunKodu[t] && FirmaKod == firmaKodTemp[t]) // EGER TUM IFLER TRUE DONDUYSE ISTEDIGIMIZ KAYITTIR VE GUNCELLEME YAPIYORYZ
						{
							cout << "Lutfen yeni degerleri giriniz..";
							cout << "Siparis Tarihi..:";
							cin >> siparisTarihi[k];
							cout << "Siparis Tutari..:";
							cin >> siparisTutari[k];
							cout << "Siparisi Alan..:";
							cin >> siparisiAlan[k];
							cout << "Urun kodu..:";
							cin >> urunKodu[t];
							cout << "Urun adeti..:";
							cin >> urunAdedi[t];
							dosyaYaz << firmaKodu[k] << " " << siparisTarihi[k] << " " << siparisTutari[k] << " " << siparisListesiDosyasi << " " << siparisiAlan[k] << " " << urunKodu[t] << endl;
							dosyaYaz2 << urunKodu[t] << " " << urunAdedi[t] << " " << firmaKodTemp[t] << endl;
						}
						else // DIGER KAYITLARIMIZ
						{
							dosyaYaz2 << urunKodu[t] << " " << urunAdedi[t] << " " << firmaKodTemp[t] << endl;
						}
					}
				}
				else// DIGER KAYITLARIMIZ
				{
					dosyaYaz << firmaKodu[k] << " " << siparisTarihi[k] << " " << siparisTutari[k] << " " << siparisListesiDosyasi << " " << siparisiAlan[k] << " " << urunKodu2[k] << endl;
				}
			}
		}

		dosyaYaz.close();
		dosyaYaz2.close();
		remove("Siparis.txt");
		remove("xyz.txt");
		int temp = rename("Siparis.tmp", "Siparis.txt"); // DOSYALARIMIZI DEGISTIRIYORUZ
		int temp2 = rename("xyz.tmp", "xyz.txt");

		cout << "Siparisiniz silinmistir..\n";
	}
}
void SiparisListeleme() {
	string firmaKodu[200];
	string siparisTarihi[200];
	string siparisTutari[200];
	string siparisiAlan[200];
	string siparisListesiDosyasi;
	string urunKodu[200];
	string urunKodu2[200];
	string urunAdeti[200];
	ifstream dosyaOku("Siparis.txt");
	ifstream dosyaOku2("xyz.txt");
	int i = 0;
	int j = 0;
	string firmaKodTemp[200];
	while (dosyaOku >> firmaKodu[i] >> siparisTarihi[i] >> siparisTutari[i] >> siparisListesiDosyasi >> siparisiAlan[i] >> urunKodu2[i]) // DOSYALARMIZI OKUYORUZ
	{
		if (dosyaOku.eof())
		{
			break;
		}
		i++;
	}
	i = 0;
	dosyaOku.close();
	while (dosyaOku2 >> urunKodu[i] >> urunAdeti[i] >> firmaKodTemp[i]) // DOSYALARMIZI OKUYORUZ
	{
		if (dosyaOku2.eof())
		{
			break;
		}
		i++;
	}
	for (int j = 0; j < i; j++)// EKRANA VERILERMIZI BASTIRIYORUZ YANÝ SÝPARÝSLERÝMÝZÝ
	{
		{
			cout << "Siparisinizin firmasinin kodu..:" << firmaKodu[j] << endl;
			cout << "Siparisinizin tarihi ..:" << siparisTarihi[j] << endl;
			cout << "Siparisinizin tutari ..:" << siparisTutari[j] << endl;
			cout << "Siparisinizi alan gorevli ..:" << siparisiAlan[j] << endl;
			cout << "Siparisinizin urun kodu..:" << urunKodu[j] << endl;
			cout << "Siparisinizin urun adeti..:" << urunAdeti[j] << endl;
			cout << "------------------------" << endl;
		}
		dosyaOku2.close();
	}
}

int main()
{

	do
	{
		cout << "Lutfen yapmak istediginiz secimi giriniz." << endl; // KULLANICIMIZIN EKRANDA GORECEGÝ MENUMUZ
		cout << "1-Urun Ekleme" << endl;
		cout << "2-Urun Arama" << endl;
		cout << "3-Urun Listeleme" << endl;
		cout << "4-Urun Guncelleme" << endl;
		cout << "5-Urun Silme" << endl;
		cout << "6-Musteri Ekle" << endl;
		cout << "7-Musteri Arama" << endl;
		cout << "8-Musteri Listeleme" << endl;
		cout << "9-Musteri Guncelleme" << endl;
		cout << "10-Musteri Silme" << endl;
		cout << "11-Siparis Olustur" << endl;
		cout << "12-Siparis Arama" << endl;
		cout << "13-Siparis Silme" << endl;
		cout << "14-Siparis Duzeltme" << endl;
		cout << "15-Siparis Raporlama/Listeleme" << endl;
		cout << "16-Cikis" << endl;
		cin >> secim; // ISTEDÝGÝ SECÝMÝ ALIYORUZ

		switch (secim)
		{
		case 1: {
			string UrunEkleKod;
			cout << "Lutfen ekleyeceginiz urunun kodunu giriniz..." << endl;
			cin >> UrunEkleKod; // URUN KODUNU KULLANICIDAN ALDIK
			urunAra(UrunEkleKod);
			if (urunVarMi != 1) // EGER DAHA ONCEDEN VARSA KAYIT BÝLDÝRÝYORUZ
			{
				UrunEkle(UrunEkleKod);

			}
			else {
				cout << "Boyle bir kaydimiz bulunmaktadir..." << endl;
			}
			break;
		}
		case 2: {

			SeciliUrunEkranaBastir();
			break;

		}
		case 3: {
			UrunListeleme();
			break;

		}
		case 4: {
			UrunGuncelleme();
			break;
		}
		case 5: {
			UrunSil();
			break;
		}
		case 6: {
			MusteriEkle();
			break;
		}
		case 7: {
			SeciliMusteriyiEkranaBastir();
			break;
		}
		case 8: {
			MusteriListeleme();
			break;
		}
		case 9: {
			MusteriGuncelleme();
			break;
		}
		case 10: {
			MusteriSil();
			break;
		}
		case 11: {
			SiparisOlustur();
			break;
		}
		case 12: {
			SiparisAra();
			break;
		}
		case 13: {
			SiparisSil();
			break;
		}
		case 14: {
			SiparisDuzeltme();
			break;
		}
		case 15: {
			SiparisListeleme();
			break;
		}
		case 16: {
			exit(0);
		}
		default: {
			break;
		}

		}

		
		cout << "Baska bir islem yapmak istiyor musunuz?(e/h)";
		cin >> cevap; // KULLANICIDAN BASKA ISLEM YAPMAK ISTEDIGINI SORUYORUZ
	

		if (secim > 15 || secim < 1) //YANLIS SECIM YAPILIRSA KULLANICIYA BÝLDÝRÝM YAPIYORUZ
		{
			cout << "Hatali secim yaptiniz...\n";
		}
		secim = 0;
		urunVarMi = 0;
		firmaVarMi = 0;
	} while (cevap=="e"||cevap=="E"||cevap=="evet"||cevap=="EVET"); // EGER EVETSE BASKA ISLEM YAPMAK ISTIYOR DEMEKTIR
}







