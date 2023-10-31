#include <stdio.h>

// 4 fonksiyonu belirleyerek yapilacak islemleri siralariz.

void print_duration(int Ay) {
    int Yil = Ay / 12;
    int Kalan_ay = Ay % 12;
    printf("-> Yil: %d Ay: %d\n", Yil, Kalan_ay);
}

void print_money(float Kredi_tutari) {
    printf("%.2f $\n", Kredi_tutari);
}

void print_entry(float Kredi_tutari, float yillik_faiz_orani, int Ay) {
    float Toplam_faiz = (Kredi_tutari / 100) * (yillik_faiz_orani / 12) * Ay;
    float Toplam_tutar = Kredi_tutari + Toplam_faiz;
    float Aylik_odeme = Toplam_tutar / Ay;
    printf("Toplam odeme:\n");
    print_money(Toplam_tutar);
    printf("Aylik odeme:\n");
    print_money(Aylik_odeme);
}

void print_full_report (float Kredi_tutari, float yillik_faiz_orani, int yil, int Ay, int Yenilenme_degeri, char *name) {
        printf("Full report for %s\n", name);
    int i = Yenilenme_degeri;
    while (i <= yil * 12 + Ay) {
        printf("--------------------------------------\n");
        print_duration(i);
        print_entry(Kredi_tutari, yillik_faiz_orani, i);
        printf("--------------------------------------\n");
        i += Yenilenme_degeri;
    }
}

// Fonksiyondaki islemlerin ardindan kod faiz hesaplamaya baslayacaktir.

int main() {

    // printf ile kodun baslik kismini yazdim.

    printf(".............................................................\n");
    printf(".....* Banka Faiz Hesaplayicisina Hoş Geldiniz ....*.\n");
    printf(".............................................................\n");

    // degerleri alir ve islemler baslar.

    char name[100];
    float Kredi_tutari;
    float yillik_faiz_orani;
    int yil;
    int Ay;
    int Yenilenme_degeri;

    // scanf ile belirtilen biilgiler alinir ve islemler kesintisiz olarak devam eder.

    printf("Lutfen İsminizi Giriniz: ");
    fgets(name, sizeof(name),stdin);
    printf("Lutfen Bir Kredi Tutari Giriniz: ");
    scanf("%f", &Kredi_tutari);
    printf("Lutfen Yillik Faiz Oranini Giriniz: ");
    scanf("%f", &yillik_faiz_orani);
    printf("Lutfen Bir Maksimum Yil Giriniz: ");
    scanf("%d", &yil);
    printf("Lutfen Bir Maksimum Ay Giriniz: ");
    scanf("%d", &Ay);
    printf("Lutfen Bir Yenileme(Ay) Degeri Giriniz: ");
    scanf("%d", &Yenilenme_degeri);

    // Son olarak ise print_full_report ile istenilen degerlerin sonucuna ulasiriz ve kod hatasiz bir sekilde calisir.

    print_full_report(Kredi_tutari, yillik_faiz_orani, yil, Ay,Yenilenme_degeri,name);

    return 0;
}
