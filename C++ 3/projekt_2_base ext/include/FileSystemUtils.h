#pragma once

#include <string>

class FileSystemElement;
class Directory;

void findAndPrintFiles(const FileSystemElement* element);
const FileSystemElement* findElementByName(const Directory* dir, const std::string& name);