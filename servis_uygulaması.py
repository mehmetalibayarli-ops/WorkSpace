servis = {}
kayit_no = 101
while True:
    print("""
    1 - Yeni Cihaz Kaydı Aç
    2 - Cihaz Durumu Güncelle (Tamirde / Parça Bekliyor / Teslime Hazır)
    3 - Cihaz Sorgula (ID ile)
    4 - Tüm Servis Kayıtlarını Listele
    5 - Kasa & Rapor (Tamamlananların Toplam Geliri)
    6 - Çıkış
    """)
    secim = int(input("Lütfen yapmak istediğini işlemi seçiniz: "))

    match secim:
        case 1:
            srv_id = f"SRV-{kayit_no}"
            kayit_no += 1

            customer_name=input("\nMüşteri ismi: ").strip().title()
            product=input("Cihaz: ").strip().title()
            price=float(input("Tahmini onarım ücreti: "))
            servis[srv_id]={"isim":customer_name, "cihaz":product, "durum":"İnceleniyor", "ücret":price}

        case 2:
            temp_srv_id = input("Lütfen servis numaranızı giriniz: ").strip().upper()
            if temp_srv_id in servis:
                new_status = input("Lütfen ürünün güncel durumunu giriniz: ").strip().title()
                servis[temp_srv_id]["durum"]=new_status
            else:
                print(f"\nHata: '{temp_srv_id}' numaralı bir servis kaydı bulunamadı!")

        case 3:
            srv_id = input("Lütfen servis numaranızı giriniz: ").strip().upper()
            if srv_id in servis:
                cihaz_bilgisi = servis[srv_id]
                print("\n" + "=" * 35)
                print(f"  KAYIT DETAYI: {srv_id}")
                print("=" * 35)
                print(f"Müşteri adı : {cihaz_bilgisi["isim"]}")
                print(f"Cihaz : {cihaz_bilgisi["cihaz"]}")
                print(f"Durum : {cihaz_bilgisi["durum"]}")
                print(f"Ücret : {cihaz_bilgisi["ücret"]} TL")
                print("=" * 35)

            else:
                print(f"\nHata: '{srv_id}' numaralı bir servis kaydı bulunamadı!")

        case 4:
            print("="*35)
            print(" Servis Kayıtları")
            for srv_id,bilgi in servis.items():
                print(f"{srv_id} | {bilgi["isim"]} | {bilgi["cihaz"]} | {bilgi["durum"]} | {bilgi["ücret"]} TL")
            print("="*35)

        case 5:
            toplam = 0
            for srv_id,bilgi in servis.items():
                if bilgi["durum"]=="Teslime Hazır":
                    toplam += bilgi["ücret"]
                    print(f"{srv_id} servis nolu {bilgi['cihaz']} cihazı tamamlandı.")

            print (f"Toplam gelir = {toplam}")

        case 6:
            print("\nÇıkış yapılıyor...")
            break

        case _:
            print("\nGeçersiz işlem numarası.")