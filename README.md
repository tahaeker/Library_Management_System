# 📖 Simple Library Management System

Modern C++ ile yazılmış **kapsamlı bir kütüphane yönetim sistemi**.  
Nesne tabanlı programlama prensipleri (Class, Object, Encapsulation) ve dosya yönetimi (File I/O) entegre edilmiştir.  
Konsol arayüzü sade, renkli ve profesyonel bir kullanıcı deneyimi sağlar.

---

## 🧩 Özellikler

- **Book ve Library sınıflarıyla OOP mimarisi**
- **books.txt** dosyasını otomatik okuyup günceller  
- Kitap ödünç alma ve iade işlemleri  
- Temiz, renkli ve hatasız **konsol arayüzü**
- Dosya tabanlı kalıcı veri yönetimi
- Platform bağımsız çalışır (Windows / Linux / macOS)

---

## 🏗️ Sınıf Yapısı

### `Book` Class
| Üye | Açıklama |
|------|-----------|
| `setBookDetails()` | Kitap bilgilerini tanımlar |
| `display()` | Kitap bilgilerini düzgün formatta döndürür |
| `borrowBook()` | Kitabı ödünç alır |
| `returnBook()` | Kitabı iade eder |
| `getSaveFormat()` | Dosyaya kaydedilecek metni döndürür |

### `Library` Class
| Üye | Açıklama |
|------|-----------|
| `loadBooksFromFile()` | `books.txt` dosyasını okur |
| `saveBooksToFile()` | Güncel durumu dosyaya kaydeder |
| `listAllBooks()` | Tüm kitapları listeler |
| `borrowBook(int id)` | ID’ye göre kitap ödünç alma işlemi |
| `returnBook(int id)` | ID’ye göre kitap iade işlemi |

---

## 💻 Konsol Arayüzü

```
=============================================
          SIMPLE LIBRARY MANAGEMENT          
=============================================
Welcome to your library system.

1) List All Books
2) Borrow a Book
3) Return a Book
4) Save & Exit
```

- Kitap listesi renkli olarak görüntülenir  
- İşlem sonuçları (başarı/hata) anlık mesajlarla belirtilir  
- Kullanıcıdan giriş alındıktan sonra ekran otomatik temizlenir  

---

## 📁 Proje Yapısı

```
Library_Management_System/
│
├── Book.h
├── Book.cpp
├── Library.h
├── Library.cpp
├── main.cpp
├── books.txt
└── README.md
```

---

## ⚙️ Kurulum ve Çalıştırma

### 🔹 Derleme
```bash
g++ main.cpp Library.cpp Book.cpp -o LibraryApp
```

### 🔹 Çalıştırma
```bash
./LibraryApp
```

> 💡 **Windows kullanıcıları** için:  
> Derleme sonrası programı `PowerShell` veya `Windows Terminal` üzerinden çalıştırmanız önerilir.  
> (Klasik “Output Console” ANSI renk kodlarını desteklemez.)

---

## 📄 books.txt Formatı

Her satır bir kitabı temsil eder:

```
ID,Title,Author,BorrowStatus
```

**BorrowStatus:**  
- `0` → Kitap mevcut  
- `1` → Kitap ödünçte  

**Örnek:**
```
1,Call of the Wild,Jack London,0
2,1984,George Orwell,1
3,To Kill a Mockingbird,Harper Lee,0
```

---

## 🧠 Kullanım Akışı

| İşlem | Açıklama |
|--------|-----------|
| **List All Books** | Kütüphanedeki tüm kitapları listeler |
| **Borrow a Book** | Girilen ID’ye ait kitabı ödünç alır |
| **Return a Book** | Girilen ID’deki kitabı iade eder |
| **Save & Exit** | Değişiklikleri dosyaya kaydeder ve çıkar |

---

## 🧪 Örnek Oturum

```
Enter Book ID to borrow: 2
Processing...
Book borrowed successfully.

Press ENTER to continue...
```

```
Enter Book ID to return: 2
Processing...
Book returned successfully.
```

---

## 🛠️ Teknik Detaylar

- **Dil:** C++17  
- **Derleyici:** GCC / MSVC  
- **Yapı:** Çok dosyalı OOP (header/source separation)  
- **Dosya I/O:** `ifstream`, `ofstream`, `sstream`  
- **Renkli Arayüz:** ANSI Escape Codes  
- **Platform:** Windows, Linux, macOS

---

## 🚀 Geliştirici Notları

- Proje arayüzü, GUI (örneğin Qt veya .NET WPF) katmanına kolayca entegre edilebilecek şekilde tasarlanmıştır.  
- `Library` sınıfındaki tüm metotlar `string` veya `bool` döner — böylece UI tarafı mesajları istediği şekilde biçimlendirebilir.  
- Konsol temizleme, animasyon ve hata yönetimi profesyonel akışta optimize edilmiştir.

---

## 🧩 Katkı

Katkıda bulunmak isteyenler:
1. Fork oluşturun  
2. Geliştirmelerinizi yapın  
3. Pull Request gönderin  

---

## 🏁 Lisans

Bu proje **MIT License** ile lisanslanmıştır.  
Ticari ve eğitim amaçlı serbestçe kullanılabilir.
