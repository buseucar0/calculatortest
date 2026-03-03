pipeline {
    agent any

    stages {
        stage('Yapılandırma (CMake Configure)') {
            steps {
                sh 'mkdir -p build'
                // CMake'e build klasörü içinde hazırlık yapmasını söylüyoruz
                sh 'cd build && cmake ..'
            }
        }
        
        stage('Derleme (Build)') {
            steps {
                // Sadece 'make' yazmak yeterli, CMake Makefile'ı bizim için oluşturdu
                sh 'cd build && make'
            }
        }
        
        stage('Test Asamasi') {
            steps {
                echo 'Test Driver calistiriliyor...'
                // Derlenen test_driver build klasörünün içinde olacak
                sh './build/test_driver'
            }
        }
    }
    
    post {
        failure {
            echo '❌ Testler patladi! CMake ile derleme basarili ama mantik hatasi var.'
        }
    }
}