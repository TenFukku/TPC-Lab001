#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class SinhVien
{
private:
    string ID;
    string Name;
    int Tuoi;
    float DiemKiemTra1;
    float DiemKiemTra2;
    float DiemChuyenCan;
    float DiemGiuaKy;
    float DiemCuoiKy;
    float TongDiem;
public:
    friend class Lop;
    void Xuat();
};

void SinhVien::Xuat()
{
    cout << endl << setw(10) << ID << setw(20) << Name << setw(6) << Tuoi << setw(10) << DiemKiemTra1 << setw(10) << DiemKiemTra2 << setw(10) << DiemChuyenCan << setw(10) << DiemGiuaKy << setw(10) << DiemCuoiKy << setw(10) << TongDiem << endl;;
}

class Lop
{
private:
    vector <SinhVien*> SinhVienLop;
public:
    Lop(){}
    void ThemSinhVien();
    void XoaSinhVien(string maSV);
    int CapNhatThongTin(string maSV);
    void XuatTatCaSinhVien();
    void TinhDiemTrungBinh(string maSV);
    void XuatSVDiemCaoNhat();
    void XuatSVDiemThapNhat();
    SinhVien* TimSinhVien(string maSV);
    void SapXep();
};

void Lop::ThemSinhVien()
{
    SinhVien* a = new SinhVien;
    string id; cin >> id; a->ID = id;
    string name; cin >> name; a->Name = name;
    int tuoi; cin >> tuoi; a->Tuoi = tuoi;
    float diem1; cin >> diem1; a->DiemKiemTra1 = diem1;
    float diem2; cin >> diem2; a->DiemKiemTra2 = diem2;
    float diemcc; cin >> diemcc; a->DiemChuyenCan = diemcc;
    float diemgk; cin >> diemgk; a->DiemGiuaKy = diemgk;
    float diemck; cin >> diemck; a->DiemCuoiKy = diemck;
    float tongdiem; cin >> tongdiem; a->TongDiem = tongdiem;
    SinhVienLop.push_back(a);
}

void Lop::XoaSinhVien(string maSV)
{
    int check = 0;
    for (int i = 0; i < SinhVienLop.size(); i++)
    {
        if (SinhVienLop[i]->ID == maSV)
        {
            check = i;
            break;
        }
    }
    for (int i = check; i < SinhVienLop.size(); i++)
    {
        SinhVienLop[i] = SinhVienLop[i + 1];
    }
    delete SinhVienLop[SinhVienLop.size() - 1];
}

int Lop::CapNhatThongTin(string maSV)
{
    for (int i = 0; i < SinhVienLop.size(); i++)
    {
        if (SinhVienLop[i]->ID == maSV)
        {
            cout << "\nNhap thong tin sinh vien: ";
            float diem1; cin >> diem1; SinhVienLop[i]->DiemKiemTra1 = diem1;
            float diem2; cin >> diem2; SinhVienLop[i]->DiemKiemTra2 = diem2;
            float diemcc; cin >> diemcc; SinhVienLop[i]->DiemChuyenCan = diemcc;
            float diemgk; cin >> diemgk; SinhVienLop[i]->DiemGiuaKy = diemgk;
            float diemck; cin >> diemck; SinhVienLop[i]->DiemCuoiKy = diemck;
            float tongdiem; cin >> tongdiem; SinhVienLop[i]->TongDiem = tongdiem;
            return 1;
        }
    }
    return 0;
}

void Lop::XuatTatCaSinhVien()
{
    cout << endl;
    cout << setw(10) << "ID" << setw(20) << "Name" << setw(6) << "Age" << setw(10) << "Diem1" << setw(10) << "Diem2" << setw(10) << "DiemCC" << setw(10) << "DiemGK" << setw(10) << "DiemCK" << setw(10) << "DiemTong\n";
    for (int i = 0; i < SinhVienLop.size(); i++)
        SinhVienLop[i]->Xuat();
}

//Vi em khong hieu lam diem trung binh la gi nen em tu nghi cach tinh Dtb luon nha
//DTB = 30%DiemCK + 30%DiemGK + 20%DiemChuyenCan + 10%Diem1 + 10%Diem2;
void Lop::TinhDiemTrungBinh(string maSV)
{
    for (int i = 0; i < SinhVienLop.size(); i++)
    {
        float DTB;
        DTB = SinhVienLop[i]->DiemCuoiKy * 0.3 + SinhVienLop[i]->DiemGiuaKy * 0.3 + SinhVienLop[i]->DiemChuyenCan * 0.2 + SinhVienLop[i]->DiemKiemTra1 * 0.1 + SinhVienLop[i]->DiemKiemTra2 * 0.1;
        cout << "\nDiem trung binh cua sinh vien la: " << DTB;
    }
}

void Lop::XuatSVDiemCaoNhat()
{
    float max = SinhVienLop[0]->TongDiem;
    int check = 0;
    for (int i = 0; i < SinhVienLop.size(); i++)
    {
        if (max < SinhVienLop[i]->TongDiem)
        {
            max = SinhVienLop[i]->TongDiem;
            check = i;
        }
    }
    SinhVienLop[check]->Xuat();
}

void Lop::XuatSVDiemThapNhat()
{
    float min = SinhVienLop[0]->TongDiem;
    int check = 0;
    for (int i = 0; i < SinhVienLop.size(); i++)
    {
        if (min > SinhVienLop[i]->TongDiem)
        {
            min = SinhVienLop[i]->TongDiem;
            check = i;
        }
    }
    SinhVienLop[check]->Xuat();
}

SinhVien* Lop::TimSinhVien(string maSV)
{
    for (int i = 0; i < SinhVienLop.size(); i++)
    {
        if (SinhVienLop[i]->ID == maSV)
        {
            return SinhVienLop[i];
        }
    }
}

void Lop::SapXep()
{
    for (int i = 0; i < SinhVienLop.size(); i++)
    {
        float max = SinhVienLop[i]->TongDiem;
        int k = 0;
        for (int j = i; j < SinhVienLop.size(); j++)
        {
            if (max < SinhVienLop[i]->TongDiem)
            {
                max = SinhVienLop[i]->TongDiem;
                k = j;
            }
        }
        swap(SinhVienLop[i], SinhVienLop[k]);
    }
}

int main()
{
    Lop TPC;
    int Choice = 1;
    while (Choice < 10 && Choice >0)
    {
        system("cls");
        cout << "1. Them thong tin sinh vien\n\n";
        cout << "2. Xoa thong tin sinh vien\n\n";
        cout << "3. Cap nhat thong tin sinh vien\n\n";
        cout << "4. Quan sat tat ca cac thong tin sinh vien\n\n";
        cout << "5. Tinh diem trung binh cua 1 sinh vien da chon\n\n";
        cout << "6. Hien thi sinh vien co tong diem cao nhat\n\n";
        cout << "7. Hien thi sinh vien co tong diem thap nhat\n\n";
        cout << "8. Tim sinh vien boi ID\n\n";
        cout << "9. Sap xep cac thong tin boi tong diem thi cua sinh vien\n\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> Choice;
        string maSV, maSV1, maSV2, maSV3;
        switch (Choice)
        {
        case 1:
            TPC.ThemSinhVien();
            break;
        case 2:
            cout << "\nNhap ma sinh vien can xoa: ";
            cin >> maSV;
            TPC.XoaSinhVien(maSV);
            break;
        case 3:
            cout << "\nNhap ma sinh vien can cap nhat: ";
            cin >> maSV1;
            if (TPC.CapNhatThongTin(maSV1) == 1)
                cout << "\nCap nhat thanh cong.";
            else
                cout << "\nCap nhat that bai.";
            break;
        case 4:
            TPC.XuatTatCaSinhVien();
            break;
        case 5:
            cout << "\nNhap ma sinh vien can tinh diem trung binh: ";
            cin >> maSV2;
            TPC.TinhDiemTrungBinh(maSV2);
            break;
        case 6:
            TPC.XuatSVDiemCaoNhat();
            break;
        case 7:
            TPC.XuatSVDiemThapNhat();
            break;
        case 8:
            cout << "\nNhap ma sinh vien can tim: ";
            cin >> maSV3;
            TPC.TimSinhVien(maSV3);
            break;
        case 9:
            TPC.SapXep();
            break;
        default:
            break;
        }
        system("pause");
    }
    return 0;
}