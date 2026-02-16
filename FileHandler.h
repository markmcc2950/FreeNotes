#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <string>
#include <QMainWindow>

class FileHandler {
public:
    void saveToFile(const std::string& newPath, const std::string& path);
    void openFromFile(std::string& pathContents, const std::string& path);
    void saveUserPreferences(const std::string& key, const std::string& value);
    void saveUserNotes(const QString& notes);
    QString sanitizeString(const QString& str);
    std::string openFileDialog();
    std::string saveFileDialog();
private:
    void toggleVisitedLocations(const QString& loc, std::pair<std::unordered_map<QString, bool>, std::unordered_map<QString, bool>>& myMap, std::unordered_map<QString, QString>& trackMap);
    std::string selectedDirectory = "";
};

extern FileHandler fh;

#endif // FILEHANDLER_H
