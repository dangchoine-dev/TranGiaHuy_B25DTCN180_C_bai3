#include <stdio.h>

#define TAI_TRONG_TOI_DA 500.0
#define NHIET_DO_MIN -18.0
#define NHIET_DO_MAX 5.0

int kiem_tra_nhap_kho_lanh(float khoi_luong_pallet,
                           float nhiet_do_bao_quan,
                           float tai_trong_hien_tai) {
    if (tai_trong_hien_tai + khoi_luong_pallet > TAI_TRONG_TOI_DA) {
        printf("Loi: Tai trong vuot qua muc cho phep!\n");
        return 0;
    }

    // Dung && de nhiet do phai nam trong ca hai gioi han
    if (nhiet_do_bao_quan >= NHIET_DO_MIN &&
        nhiet_do_bao_quan <= NHIET_DO_MAX) {
        return 1;
    } else {
        printf("Loi: Nhiet do %.1f do C khong phu hop kho lanh!\n",
               nhiet_do_bao_quan);
        return 0;
    }
}

int main() {
    float tai_trong_hien_tai = 320.0;
    float khoi_luong_pallet;
    float nhiet_do_bao_quan;

    printf("=== KIEM DINH NHAP KHO LANH SMARTLOG ===\n");
    printf("Tai trong hien tai: %.1f / %.1f kg\n",
           tai_trong_hien_tai, TAI_TRONG_TOI_DA);

    printf("Nhap khoi luong pallet (kg): ");
    if (scanf("%f", &khoi_luong_pallet) != 1 || khoi_luong_pallet <= 0) {
        printf("Du lieu khoi luong khong hop le!\n");
        return 1;
    }

    printf("Nhap nhiet do bao quan (do C): ");
    if (scanf("%f", &nhiet_do_bao_quan) != 1) {
        printf("Du lieu nhiet do khong hop le!\n");
        return 1;
    }

    int ket_qua = kiem_tra_nhap_kho_lanh(
        khoi_luong_pallet, nhiet_do_bao_quan, tai_trong_hien_tai
    );

    if (ket_qua == 1) {
        tai_trong_hien_tai += khoi_luong_pallet;
        printf("PHE DUYET: Nhap kho thanh cong!\n");
        printf("Tai trong sau khi nhap: %.1f kg\n", tai_trong_hien_tai);
    } else {
        printf("TU CHOI: Kien hang khong du dieu kien!\n");
        printf("Tai trong giu nguyen: %.1f kg\n", tai_trong_hien_tai);
    }

    return 0;
}
/*
Phan tich loi:
Loi nam o dieu kien kiem tra nhiet do
Toan tu || sai nen nhiet do 25 do C va -25 do C van duoc chap nhan
Sua || thanh && de nhiet do phai nam trong khoang tu -18 den 5 do C
Test case:
1. Nhap 50kg, nhiet do 25 do C, tai trong hien tai 320kg
   Ket qua cu: Cho phep nhap kho
   Ket qua dung: Tu choi do sai nhiet do

2. Nhap 50kg, nhiet do -25 do C, tai trong hien tai 320kg
   Ket qua cu: Cho phep nhap kho
   Ket qua dung: Tu choi do sai nhiet do

3. Nhap 100kg, nhiet do -10 do C, tai trong hien tai 320kg
   Ket qua cu: Cho phep nhap kho
   Ket qua dung: Cho phep nhap kho
*/
