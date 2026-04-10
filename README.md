# 🎲 Monte Carlo Casino Simulation
### Martingale vs. Safe Betting

![C++](https://img.shields.io/badge/C%2B%2B-17-blue?style=flat-square&logo=c%2B%2B)
![Python](https://img.shields.io/badge/Python-3.10-yellow?style=flat-square&logo=python)

Dự án mô phỏng rủi ro tài chính giữa chiến thuật Gấp thếp 
và Đánh an toàn bằng phương pháp Monte Carlo.

---

## 🚀 Tính năng nổi bật

* **Engine Đa luồng (Multi-threading):**
  - Khai thác tối đa sức mạnh 16 luồng CPU.
  - Mô phỏng hàng triệu ván cược trong thời gian ngắn.
* **Mô hình lập trình hướng đối tượng:**
  - **Strategy Pattern:** Quản lý linh hoạt các thuật toán cược.
  - **Factory Pattern:** Khởi tạo người chơi dễ dàng.
* **Pipeline dữ liệu tự động:**
  - C++ tính toán logic và xuất file CSV.
  - Tự động gọi Python để phân tích và vẽ biểu đồ.

---

## 🛠️ Kiến trúc Hệ thống

### 1. C++ Core (Simulation Layer)
* **Xác suất:** House Edge chuẩn Casino (48.6%).
* **Ngẫu nhiên:** Bộ sinh số `mt19937` cực chuẩn.
* **Hiệu năng:** Kiến trúc **No-Mutex** tối ưu tốc độ ghi file.

### 2. Python Analysis (Visualization)
* **Thống kê:** Tính toán Kỳ vọng (EV) từ 16 vũ trụ độc lập.
* **Trực quan:** Vẽ bộ 3 biểu đồ so sánh:
  - Kịch bản xui xẻo (Phá sản nhanh).
  - Kịch bản may mắn (Trụ lại lâu).
  - Đường cong trung bình (Sự thật toán học).

---

## 📊 Phân tích kết quả

1. **Gấp thếp:** Thắng nhiều ván nhỏ nhưng dễ trắng tay 
   tức thì khi gặp chuỗi thua đủ dài.
2. **An toàn:** Vốn bị bào mòn chậm do lợi thế sòng bạc.
3. **Kết luận:** Mọi con đường đều dẫn về vạch 0 VNĐ.

---

## ⚙️ Cài đặt & Sử dụng

### 1. Chuẩn bị
Tạo thư mục `data/` thủ công tại thư mục gốc của dự án.

### 2. Cài đặt thư viện Python
Copy và chạy lệnh này trong Terminal:
```bash
   pip install pandas matplotlib numpy
```
### 3. Thực thi dự án
* Mở Solution bằng Visual Studio.
* Nhấn **F5** hoặc nút **Local Windows Debugger**.
* Chờ C++ chạy xong, biểu đồ sẽ tự động hiển thị.

---
> **Lưu ý:** Dự án chỉ dùng cho mục đích học tập và 
> nghiên cứu xác suất, không khuyến khích cờ bạc.

**Tác giả:** [Sangle]