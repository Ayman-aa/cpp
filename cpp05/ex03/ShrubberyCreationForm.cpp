# include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this == &other)
        return *this;
    AForm::operator=(other);
    target = other.target;
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if  (!isSigned())
        throw FormNotSignedException();
    if (getGradeToExecute() < executor.getGrade())
        throw GradeTooLowException();
    std::ofstream file(target + "_shrubbery");
    if (!file.is_open())
        throw FileNotOpenException();
    
    file << "       _-_\n";
    file << "    /~~   ~~\\\n";
    file << " /~~         ~~\\\n";
    file << "{               }\n";
    file << " \\  _-     -_  /\n";
    file << "   ~  \\\\ //  ~\n";
    file << "_- -   | | _- _\n";
    file << "  _ -  | |   -_\n";
    file << "      // \\\\\n";
    
    file.close();
}

const char *ShrubberyCreationForm::FileNotOpenException::what() const throw() {
    return "File not open";
}