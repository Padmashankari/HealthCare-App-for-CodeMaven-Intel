#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QComboBox>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QMainWindow window;
    window.setGeometry(50, 50, 500, 500);

    QLabel *patientInfoLabel = new QLabel("Patient Information", &window);
    patientInfoLabel->setGeometry(50, 50, 150, 20);

    QLabel *nameLabel = new QLabel("Name:", &window);
    nameLabel->setGeometry(50, 80, 50, 20);

    QLineEdit *nameLineEdit = new QLineEdit(&window);
    nameLineEdit->setGeometry(110, 80, 150, 20);

    QLabel *genderLabel = new QLabel("Gender:", &window);
    genderLabel->setGeometry(50, 110, 50, 20);

    QComboBox *genderComboBox = new QComboBox(&window);
    genderComboBox->setGeometry(110, 110, 100, 20);
    genderComboBox->addItem("Male");
    genderComboBox->addItem("Female");

    QLabel *ageLabel = new QLabel("Age:", &window);
    ageLabel->setGeometry(50, 140, 50, 20);

    QLineEdit *ageLineEdit = new QLineEdit(&window);
    ageLineEdit->setGeometry(110, 140, 50, 20);

    QLabel *contactLabel = new QLabel("Contact No.:", &window);
    contactLabel->setGeometry(50, 170, 70, 20);

    QLineEdit *contactLineEdit = new QLineEdit(&window);
    contactLineEdit->setGeometry(120, 170, 150, 20);

    QLabel *healthInfoLabel = new QLabel("Health Information", &window);
    healthInfoLabel->setGeometry(50, 220, 150, 20);

    QLabel *bloodPressureLabel = new QLabel("Blood Pressure:", &window);
    bloodPressureLabel->setGeometry(50, 250, 100, 20);

    QLineEdit *bloodPressureLineEdit = new QLineEdit(&window);
    bloodPressureLineEdit->setGeometry(150, 250, 50, 20);

    QLabel *temperatureLabel = new QLabel("Temperature:", &window);
    temperatureLabel->setGeometry(50, 280, 100, 20);

    QLineEdit *temperatureLineEdit = new QLineEdit(&window);
    temperatureLineEdit->setGeometry(150, 280, 50, 20);

    QLabel *heartRateLabel = new QLabel("Heart Rate:", &window);
    heartRateLabel->setGeometry(50, 310, 100, 20);

    QLineEdit *heartRateLineEdit = new QLineEdit(&window);
    heartRateLineEdit->setGeometry(150, 310, 50, 20);

    QLabel *symptomsLabel = new QLabel("Symptoms:", &window);
    symptomsLabel->setGeometry(50, 340, 70, 20);

    QTextEdit *symptomsTextEdit = new QTextEdit(&window);
    symptomsTextEdit->setGeometry(130, 340, 150, 50);

    QPushButton *submitButton = new QPushButton("Submit", &window);
    submitButton->setGeometry(50, 410, 100, 30);

    QPushButton *clearButton = new QPushButton("Clear", &window);
    clearButton->setGeometry(170, 410, 100, 30);

    window.show();
    
// add signal/slot connections to submitButton and clearButton
QObject::connect(submitButton, &QPushButton::clicked, [&](){
    QString name = nameLineEdit->text();
    QString gender = genderComboBox->currentText();
    QString age = ageLineEdit->text();
    QString contact = contactLineEdit->text();
    QString bloodPressure = bloodPressureLineEdit->text();
    QString temperature = temperatureLineEdit->text();
    QString heartRate = heartRateLineEdit->text();
    QString symptoms = symptomsTextEdit->toPlainText();

    // Do something with the input data here, e.g. save to a file or database
});

QObject::connect(clearButton, &QPushButton::clicked, [&](){
    nameLineEdit->clear();
    genderComboBox->setCurrentIndex(0);
    ageLineEdit->clear();
    contactLineEdit->clear();
    bloodPressureLineEdit->clear();
    temperatureLineEdit->clear();
    heartRateLineEdit->clear();
    symptomsTextEdit->clear();
});

return app.exec();
