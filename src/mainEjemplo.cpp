#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QGroupBox>
#include <QSpacerItem>
#include <QHBoxLayout>
#include <QDateTime>
#include <QPixmap>
#include <QIcon>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget mainWindow;
    mainWindow.setWindowTitle("Health Center Connect");
    mainWindow.setStyleSheet("background-color: #1c1c1c; color: #ffffff;");

  
    mainWindow.setFixedSize(1200, 800);

    QVBoxLayout *mainLayout = new QVBoxLayout(&mainWindow);

    QWidget *topPanel = new QWidget(&mainWindow);
    topPanel->setStyleSheet("background-color: #1f1f1f; padding: 10px;");
    QHBoxLayout *topPanelLayout = new QHBoxLayout(topPanel);

    QLabel *clinicLabel = new QLabel("Health Center Connect", topPanel);
    clinicLabel->setStyleSheet("font: bold 24px; font-family: Arial;");
    topPanelLayout->addWidget(clinicLabel);

    QPushButton *menuButton = new QPushButton(topPanel);
    menuButton->setIcon(QIcon(":/menu_icon.png"));
    menuButton->setIconSize(QSize(32, 32));
    menuButton->setStyleSheet("background-color: transparent; border: none;");
    topPanelLayout->addWidget(menuButton);

    mainLayout->addWidget(topPanel);

    
    QGroupBox *sidebarGroupBox = new QGroupBox(&mainWindow);
    sidebarGroupBox->setStyleSheet("background-color: #1f1f1f; font-family: Arial;");
    sidebarGroupBox->setTitle("Menu");
    QVBoxLayout *sidebarLayout = new QVBoxLayout(sidebarGroupBox);

    QPushButton *scheduleButton = new QPushButton("Schedule", sidebarGroupBox);
    scheduleButton->setStyleSheet("background-color: #222222; color: #ffffff; font-family: Arial; font-size: 20px; padding: 10px;");
    sidebarLayout->addWidget(scheduleButton);

    QPushButton *medicalRecordsButton = new QPushButton("Medical Records", sidebarGroupBox);
    medicalRecordsButton->setStyleSheet("background-color: #222222; color: #ffffff; font-family: Arial; font-size: 20px; padding: 10px;");
    sidebarLayout->addWidget(medicalRecordsButton);

    QPushButton *chatButton = new QPushButton("Chat", sidebarGroupBox);
    chatButton->setStyleSheet("background-color: #222222; color: #ffffff; font-family: Arial; font-size: 20px; padding: 10px;");
    sidebarLayout->addWidget(chatButton);

    QPushButton *reportsButton = new QPushButton("Reports", sidebarGroupBox);
    reportsButton->setStyleSheet("background-color: #222222; color: #ffffff; font-family: Arial; font-size: 20px; padding: 10px;");
    sidebarLayout->addWidget(reportsButton);

    QPushButton *settingsButton = new QPushButton("Settings", sidebarGroupBox);
    settingsButton->setStyleSheet("background-color: #222222; color: #ffffff; font-family: Arial; font-size: 20px; padding: 10px;");
    sidebarLayout->addWidget(settingsButton);

    QPushButton *analyticsButton = new QPushButton("Analytics", sidebarGroupBox);
    analyticsButton->setStyleSheet("background-color: #222222; color: #ffffff; font-family: Arial; font-size: 20px; padding: 10px;");
    sidebarLayout->addWidget(analyticsButton);

    QPushButton *emergencyButton = new QPushButton("Emergency", sidebarGroupBox);
    emergencyButton->setStyleSheet("background-color: #222222; color: #ffffff; font-family: Arial; font-size: 20px; padding: 10px;");
    sidebarLayout->addWidget(emergencyButton);

    sidebarGroupBox->setLayout(sidebarLayout);
    mainLayout->addWidget(sidebarGroupBox);

    QWidget *centralWidget = new QWidget(&mainWindow);
    centralWidget->setStyleSheet("background-color: #1f1f1f;");
    QVBoxLayout *centralLayout = new QVBoxLayout(centralWidget);

    QLabel *titleLabel = new QLabel("Welcome to Health Center Connect", centralWidget);
    titleLabel->setStyleSheet("color: #ffffff; font: bold 36px; font-family: Arial;");
    centralLayout->addWidget(titleLabel);

    QLabel *descriptionLabel = new QLabel("Your personal assistant in efficient clinic management", centralWidget);
    descriptionLabel->setStyleSheet("color: #cccccc; font: italic 20px; font-family: Arial;");
    centralLayout->addWidget(descriptionLabel);

   
    QLabel *appointmentsLabel = new QLabel("Upcoming Appointments", centralWidget);
    appointmentsLabel->setStyleSheet("color: #ffffff; font: bold 24px; font-family: Arial;");
    centralLayout->addWidget(appointmentsLabel);

    QDateTime currentDateTime = QDateTime::currentDateTime();
    for (int i = 0; i < 5; ++i) {
        QDateTime appointmentDateTime = currentDateTime.addDays(i).addSecs(3600 * (i + 1));
        QLabel *appointmentTextLabel = new QLabel(appointmentDateTime.toString("dddd, MMMM d, yyyy - hh:mm AP"), centralWidget);
        appointmentTextLabel->setStyleSheet("color: #cccccc; font: 18px; font-family: Arial;");
        centralLayout->addWidget(appointmentTextLabel);
    }

    centralWidget->setLayout(centralLayout);
    mainLayout->addWidget(centralWidget);

    mainLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding));

    
    mainWindow.setLayout(mainLayout);

    
    mainWindow.show();

    return app.exec();
}
