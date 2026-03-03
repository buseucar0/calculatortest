pipeline {
    agent any

    stages {
        stage('Temizlik ve Derleme') {
            steps {
                echo 'Eski derleme artiklari temizleniyor...'
                sh 'make clean'
                
                echo 'C++ kodlari derleniyor...'
                sh 'make'
            }
        }
        
        stage('Test Asamasi') {
            steps {
                echo 'Test Driver calistiriliyor...'
                // Eger bu test 1 dondururse, Jenkins bu asamayi KIRMIZI (Failed) yapacak!
                sh 'make test'
            }
        }
    }
    
    // Asamalar bittikten sonra konsola basilacak mesajlar
    post {
        success {
            echo '✅ HARIKA! Tum testler gecti. Senaryo basarili.'
        }
        failure {
            echo '❌ BUM! Testler patladi (Bekledigimiz gibi!). Gidip test_driver.cpp dosyasini duzeltmemiz lazim.'
        }
    }
}