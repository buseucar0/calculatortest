# Derleyici ve bayraklar 
CXX = g++
CXXFLAGS = -Wall -std=c++14 -Iinclude

# Klasör yolları
SRC_DIR = src
BUILD_DIR = build

# Çıktı dosyasının adı ve yolu
TARGET = $(BUILD_DIR)/calculator

# src klasöründeki tüm .cpp dosyalarını otomatik bul
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# .cpp dosyalarının isimlerini al, .o yap ve build klasörüne yönlendir
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Varsayılan hedef
all: $(TARGET)

# Ana programı derleme kuralı
$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Her bir .cpp dosyasını build klasöründe .o dosyasına dönüştürme kuralı
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

# ==========================================
# --- YENİ EKLENEN DRIVER TEST KISMI ---
# ==========================================

TEST_SRC = tests/test_driver.cpp
TEST_TARGET = $(BUILD_DIR)/test_driver

# main.o HARİÇ diğer tüm .o dosyalarını alıyoruz (Driver kendi main'ine sahip)
TEST_OBJS = $(filter-out $(BUILD_DIR)/main.o, $(OBJS))

# Driver'ı derleme kuralı (GTest flagleri kaldırıldı)
test_build: $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(TEST_SRC) $(TEST_OBJS) -o $(TEST_TARGET)

# Driver'ı çalıştır
test: test_build
	./$(TEST_TARGET)