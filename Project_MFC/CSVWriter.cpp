#include "pch.h"
#include "CSVWriter.h"
#include "pch.h"
#include "CSVFileReader.h"
#include <sstream>
#include <afx.h>

CSVWriter::CSVWriter(const CString& filePath)
    : m_filePath(filePath)
{
}

bool CSVWriter::WriteCSV(const std::vector<std::vector<std::string>>& data)
{
    CStdioFile file;
    CFileException fileException;
    if (!file.Open(m_filePath, CFile::modeCreate | CFile::modeWrite | CFile::typeText, &fileException))
    {
        AfxMessageBox(_T("Error while saving file!"), MB_ICONERROR);
        return false;
    }

    for (const auto& row : data)
    {
        std::string line;
        for (size_t i = 0; i < row.size(); ++i)
        {
            line += row[i];
            if (i < row.size() - 1)
                line += ",";
        }

        line += "\n";
        CString lineCString(line.c_str());
        file.WriteString(lineCString);
    }

    file.Close();
    AfxMessageBox(_T("Data saved successfully"), MB_ICONINFORMATION);
    return true;
}