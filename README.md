## Mã hóa AES và DES

### Các bước thực hiện


#### Mã hóa (DES/Encrypt/ hoặc AES/Encrypt/):  
key.txt:  
DES: 16 ký tự hex (VD: 0123456789ABCDEF)  
AES: 32 ký tự hex (VD: 000102030405060708090A0B0C0D0E0F)


plaintext.txt: Văn bản cần mã hóa (VD: LuongGiaNghiemk67)


### Giải mã (DES/Decrypt/ hoặc AES/Decrypt/):  
Sao chép key.txt và ciphertext.txt từ thư mục mã hóa sang.




### Biên dịch  

Mã hóa DES: cd DES/Encrypt && g++ des_encrypt.cpp ../../src/des.cpp ../../src/utils.cpp -o des_encrypt  
Giải mã DES: cd DES/Decrypt && g++ des_decrypt.cpp ../../src/des.cpp ../../src/utils.cpp -o des_decrypt  
Mã hóa AES: cd AES/Encrypt && g++ aes_encrypt.cpp ../../src/aes.cpp ../../src/utils.cpp -o aes_encrypt  
Giải mã AES: cd AES/Decrypt && g++ aes_decrypt.cpp ../../src/aes.cpp ../../src/utils.cpp -o aes_decrypt


### Chạy chương trình  

Mã hóa: ./des_encrypt hoặc ./aes_encrypt → Tạo ciphertext.txt  
Giải mã: ./des_decrypt hoặc ./aes_decrypt → Tạo decrypted.txt


### Kết quả  

ciphertext.txt: Dữ liệu mã hóa (dạng hex)  
decrypted.txt: Văn bản đã giải mã



