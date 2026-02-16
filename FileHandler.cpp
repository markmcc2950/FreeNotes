#include "FileHandler.h"
#include <windows.h>
#include <fstream>
#include <QMainWindow>
#include <QRegularExpression>

#include <windows.h>
#include <shlobj.h>
#include <shobjidl.h>

FileHandler fh;

std::string FileHandler::openFileDialog() {
    HRESULT hr = CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);
    if (FAILED(hr)) return "";

    IFileOpenDialog* pFileOpen = nullptr;
    hr = CoCreateInstance(CLSID_FileOpenDialog, nullptr, CLSCTX_INPROC_SERVER,
                          IID_PPV_ARGS(&pFileOpen));

    if (FAILED(hr)) {
        CoUninitialize();
        return "";
    }

    COMDLG_FILTERSPEC filters[] = {
        { L"Text Files", L"*.txt;*.docx;*.doc;" },
        { L"All Files",   L"*.*" }
    };
    pFileOpen->SetFileTypes(2, filters);

    hr = pFileOpen->Show(nullptr);
    if (FAILED(hr)) {
        pFileOpen->Release();
        CoUninitialize();
        return "";
    }

    IShellItem* pItem = nullptr;
    hr = pFileOpen->GetResult(&pItem);
    if (FAILED(hr)) {
        pFileOpen->Release();
        CoUninitialize();
        return "";
    }

    PWSTR filePath = nullptr;
    pItem->GetDisplayName(SIGDN_FILESYSPATH, &filePath);

    std::wstring wpath(filePath);
    std::string path(wpath.begin(), wpath.end());

    CoTaskMemFree(filePath);
    pItem->Release();
    pFileOpen->Release();
    CoUninitialize();

    return path;
}

std::string FileHandler::saveFileDialog() {
    HRESULT hr = CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);
    if (FAILED(hr)) return "";

    IFileSaveDialog* pFileSave = nullptr;
    hr = CoCreateInstance(CLSID_FileSaveDialog, nullptr, CLSCTX_INPROC_SERVER,
                          IID_PPV_ARGS(&pFileSave));

    if (FAILED(hr)) {
        CoUninitialize();
        return "";
    }

    COMDLG_FILTERSPEC filters[] = {
        { L"Text Files", L"*.txt" },
        { L"Microsoft Word Files", L".docx"}
    };
    pFileSave->SetFileTypes(2, filters);
    pFileSave->SetDefaultExtension(L"txt");
    pFileSave->SetFileName(L"output");

    hr = pFileSave->Show(nullptr);
    if (FAILED(hr)) {
        pFileSave->Release();
        CoUninitialize();
        return "";
    }

    IShellItem* pItem = nullptr;
    hr = pFileSave->GetResult(&pItem);
    if (FAILED(hr)) {
        pFileSave->Release();
        CoUninitialize();
        return "";
    }

    PWSTR filePath = nullptr;
    pItem->GetDisplayName(SIGDN_FILESYSPATH, &filePath);

    std::wstring wpath(filePath);
    std::string path(wpath.begin(), wpath.end());

    CoTaskMemFree(filePath);
    pItem->Release();
    pFileSave->Release();
    CoUninitialize();

    return path;
}

QString FileHandler::sanitizeString(const QString& str) {
    int strPos = -1;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '\\') {
            strPos = i;
        }
    }

    if (strPos >= 0) {
        // Take the string from the final slash until the end of the file name, including extension
        QString tempStr = str.mid(strPos + 1, str.length() - strPos - 1);
        return tempStr;
    }

    return "";
}

void FileHandler::saveToFile(const std::string& pathContents, const std::string& path) {    
    std::ofstream pathsFile(path);

    if (pathsFile.is_open()) {
        for (int i = 0; i < pathContents.size(); i++) {
            pathsFile << pathContents[i];
        }
    }
    pathsFile.close();
}

void FileHandler::openFromFile(std::string& fileContents, const std::string& path) {
    std::ifstream pathsFile(path);

    fileContents.clear();

    // Verify the file exists, and that we haven't populated our path list yet
    if (pathsFile && fileContents.empty()) {
        std::string line;
        while (std::getline(pathsFile, line)) {
            fileContents = fileContents + line + "\n";
        }
    }
}
