#include "File.h"

File::File(const std::string& name): FSElement(name){
    
}

void File::print(size_t spaces, std::ostream& os) const{

    auto print_spaces = [spaces](std::ostream& os){
        for(int i=0;i<spaces;++i)
            os << " ";
    };

    print_spaces(os);

    os << _name << " (FILE)" <<std::endl;
}