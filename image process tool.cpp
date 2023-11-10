#include <QApplication>
#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QFileDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QImageReader>
#include <QImageWriter>
#include <QGraphicsBlurEffect>
#include <QGraphicsColorizeEffect>
#include <QGraphicsOpacityEffect>
#include <QGraphicsBlurEffect>

class ImageProcessingTool : public QMainWindow {
    Q_OBJECT

public:
    ImageProcessingTool(QWidget *parent = nullptr) : QMainWindow(parent) {
        setWindowTitle("Image Processing Tool");

        createMenu();

        scene = new QGraphicsScene(this);
        view = new QGraphicsView(scene);
        setCentralWidget(view);
    }

private slots:
    void loadImage() {
        QString filePath = QFileDialog::getOpenFileName(this, "Open Image", "", "Images (*.png *.jpg *.bmp *.gif)");
        if (!filePath.isEmpty()) {
            QImageReader reader(filePath);
            QImage image = reader.read();
            displayImage(image);
        }
    }

    void applyGrayscale() {
        applyImageFilter(new QGraphicsColorizeEffect(this));
    }

    void applyBlur() {
        applyImageFilter(new QGraphicsBlurEffect(this));
    }

    void applySharpen() {
        QGraphicsOpacityEffect* opacityEffect = new QGraphicsOpacityEffect(this);
        opacityEffect->setOpacity(0.5);
        applyImageFilter(opacityEffect);
    }

    void adjustBrightness() {
        // Implement brightness adjustment
    }

    void adjustContrast() {
        // Implement contrast adjustment
    }

    void cropImage() {
        // Implement image cropping
    }

    void resizeImage() {
        // Implement image resizing
    }

    void saveImage() {
        QString filePath = QFileDialog::getSaveFileName(this, "Save Image", "", "Images (*.png *.jpg *.bmp *.gif)");
        if (!filePath.isEmpty()) {
            QGraphicsPixmapItem* pixmapItem = dynamic_cast<QGraphicsPixmapItem*>(scene->items().first());
            if (pixmapItem) {
                QPixmap pixmap = pixmapItem->pixmap();
                pixmap.save(filePath);
            }
        }
    }

private:
    void createMenu() {
        QMenu* fileMenu = menuBar()->addMenu("File");
        QAction* loadAction = fileMenu->addAction("Load Image");
        connect(loadAction, &QAction::triggered, this, &ImageProcessingTool::loadImage);

        QAction* saveAction = fileMenu->addAction("Save Image");
        connect(saveAction, &QAction::triggered, this, &ImageProcessingTool::saveImage);

        QMenu* filtersMenu = menuBar()->addMenu("Filters");
        QAction* grayscaleAction = filtersMenu->addAction("Grayscale");
        connect(grayscaleAction, &QAction::triggered, this, &ImageProcessingTool::applyGrayscale);

        QAction* blurAction = filtersMenu->addAction("Blur");
        connect(blurAction, &QAction::triggered, this, &ImageProcessingTool::applyBlur);

        QAction* sharpenAction = filtersMenu->addAction("Sharpen");
        connect(sharpenAction, &QAction::triggered, this, &ImageProcessingTool::applySharpen);

        QMenu* adjustmentsMenu = menuBar()->addMenu("Adjustments");
        QAction* brightnessAction = adjustmentsMenu->addAction("Adjust Brightness");
        connect(brightnessAction, &QAction::triggered, this, &ImageProcessingTool::adjustBrightness);

        QAction* contrastAction = adjustmentsMenu->addAction("Adjust Contrast");
        connect(contrastAction, &QAction::triggered, this, &ImageProcessingTool::adjustContrast);

        QMenu* transformMenu = menuBar()->addMenu("Transform");
        QAction* cropAction = transformMenu->addAction("Crop");
        connect(cropAction, &QAction::triggered, this, &ImageProcessingTool::cropImage);

        QAction* resizeAction = transformMenu->addAction("Resize");
        connect(resizeAction, &QAction::triggered, this, &ImageProcessingTool::resizeImage);
    }

    void displayImage(const QImage& image) {
        scene->clear();
        QGraphicsPixmapItem* pixmapItem = new QGraphicsPixmapItem(QPixmap::fromImage(image));
        scene->addItem(pixmapItem);
        view->setScene(scene);
    }

    void applyImageFilter(QGraphicsEffect* effect) {
        QGraphicsPixmapItem* pixmapItem = dynamic_cast<QGraphicsPixmapItem*>(scene->items().first());
        if (pixmapItem) {
            pixmapItem->setGraphicsEffect(effect);
        }
    }

    QGraphicsScene* scene;
    QGraphicsView* view;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    ImageProcessingTool tool;
    tool.show();

    return app.exec();
}

#include "main.moc"

