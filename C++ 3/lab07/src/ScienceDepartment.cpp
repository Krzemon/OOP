#include "ScienceDepartment.h"

int ScienceDepartment::num = 0;

void ScienceDepartment::add_divisions(const std::vector<std::string>& divisions) {
    divisions_.insert(divisions_.end(), divisions.begin(), divisions.end());
}

void ScienceDepartment::info() const {
    std::cout << "["<< num++ <<"] [Science]: '" << name_ << "' [divisions]: ";
    if (divisions_.empty()) {
        std::cout << "None";
    } else {
        for (size_t i = 0; i < divisions_.size(); ++i) {
            std::cout << divisions_[i];
            if (i < divisions_.size() - 1) std::cout << " ";
        }
    }
    std::cout << "\n";
}