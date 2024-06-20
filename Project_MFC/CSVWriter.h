#pragma once
#include <vector>
#include <string>
#include <atlstr.h> // U¿ycie CString
#include <afx.h> // U¿ycie CStdioFile

class CSVWriter
{
public:
    CSVWriter(const CString& filePath);
    bool WriteCSV(const std::vector<std::vector<std::string>>& data);

private:
    CString m_filePath;
};