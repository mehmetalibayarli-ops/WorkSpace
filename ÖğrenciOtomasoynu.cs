using System;
using System.Collections.Generic;
using System.Linq;

namespace toDoList
{
    internal class Program
    {
        static void Main(string[] args)
        {
            List<string> ogrenciler = new List<string>();
            List<int> notlar = new List<int>();

            int input=0;
            while(input != 5)
            {
                Console.WriteLine("\n---===== Öğrenci Otomasyonu =====---");
                Console.WriteLine("\n1 - Öğrenci ve Not Listele.");
                Console.WriteLine("2 - Yeni Öğrenci Ekle.");
                Console.WriteLine("3 - Öğrenci Sil.");
                Console.WriteLine("4 - Sınıf İstatistikleri.");
                Console.WriteLine("5 - Çıkış.");

                Console.Write("\nYapmak istediğiniz işlemi seçiniz :");
                input = int.Parse(Console.ReadLine());

                switch (input)
                {
                    case 1:
                        if (ogrenciler.Count == 0)
                        {
                            Console.WriteLine("\nÖğrenci listesli boş.");
                            break;
                        }
                        for(int i=0 ; i < ogrenciler.Count; i++)
                        {
                            Char harfNotu;
                            if (notlar[i]>84)
                            {
                                harfNotu = 'A';
                            }
                            else if (notlar[i] > 69)
                            {
                                harfNotu = 'B';
                            }
                            else if (notlar[i] > 49)
                            {
                                harfNotu = 'C';
                            }
                            else
                            {
                                harfNotu = 'F';
                            }

                            Console.WriteLine($"{i+1}. {ogrenciler[i]} - Not: {notlar[i]} (Harf: {harfNotu})");
                        }

                    break;

                    case 2:
                    string tempInput;
                    Console.Write("\nYeni öğrencinin ismini giriniz: ");
                    tempInput = Console.ReadLine();
                        if (ogrenciler.Contains(tempInput))
                        {
                            Console.WriteLine("Mevcutta olan öğrenci kaydı.");
                            break;
                        }
                        else
                        {
                            ogrenciler.Add(tempInput);
                            Console.Write("Öğrencinin notunu giriniz :");
                            notlar.Add(int.Parse(Console.ReadLine()));
                        }
                    break;

                    case 3:
                    int tempIndex;
                        if (ogrenciler.Count == 0)
                        {
                            Console.WriteLine("\nListe boş.");
                            break;
                        }
                        Console.WriteLine("Silmek istediğiniz öğrenciyi seçiniz: ");
                        for(int i = 0 ; i < ogrenciler.Count; i++)
                        {
                            Console.WriteLine($"{i+1}- {ogrenciler[i]}");
                        }
                        tempIndex=(int.Parse(Console.ReadLine())-1);

                        if(tempIndex>=0 && tempIndex < ogrenciler.Count)
                        {
                            Console.WriteLine($"\n{ogrenciler[tempIndex]} listeden başarıyla silindi.");
                            ogrenciler.RemoveAt(tempIndex);
                            notlar.RemoveAt(tempIndex);
                        }
                        else
                        {
                            Console.WriteLine("\nGeçersiz öğrenci girişi.");
                            break;
                        }
                    break;

                    case 4:
                    if (ogrenciler.Count == 0)
                        {
                            Console.WriteLine("\nListe boş.");
                            break;
                        }
                    int sum=0;
                    int enYuksekNot = notlar.Max();
                    int enYuksekIndex = notlar.IndexOf(enYuksekNot);
                    for(int i =0; i < ogrenciler.Count; i++)
                        {
                            sum += notlar[i];
                        }
                    Console.WriteLine($"\nSınıfın not ortalaması: {sum/ogrenciler.Count}");
                    Console.WriteLine($"En yüksek not: {enYuksekNot} - {ogrenciler[enYuksekIndex]}");    
                    break;

                    case 5:
                    Console.WriteLine("\nÇıkış yapılıyor...");
                    break;

                    default:
                    Console.WriteLine("\nGeçersiz işlem.");
                    break;
                }


            }
        }
    }
}