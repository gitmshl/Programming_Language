
class MyBaseException(BaseException):
    def what(self):
        return ""


class DoubleVarUse(MyBaseException):
    def __init__(self, line, line_number):
        self.line_number = line_number + 1
        self.line = line

    def what(self):
        return f"Повторное использование переменной с одним именем. Строка: {self.line_number}\n{self.line}"


class SyntaxError(MyBaseException):
    def __init__(self, line, line_number, msg="Ошибка синтаксиса."):
        self.line_number = line_number + 1
        self.line = line
        self.msg = msg
    
    def what(self):
        return f"{self.msg} Строка: {self.line_number}\n{self.line}"


class DriverNotFound(MyBaseException):
    def __init__(self, line, line_number):
        self.line_number = line_number + 1
        self.line = line
    
    def what(self):
        return f"Драйвер не найден. Строка: {self.line_number}\n{self.line}"


class UnknownGlobalType(MyBaseException):
    def __init__(self, line, line_number):
        self.line_number = line_number + 1
        self.line = line
    
    def what(self):
        return f"Неизвестный глобальный тип. Строка: {self.line_number}\n{self.line}"

class ModuleNotFound(MyBaseException):
    def __init__(self, line, line_number):
        self.line_number = line_number + 1
        self.line = line
    
    def what(self):
        return f"Неизвестный глобальный тип. Строка: {self.line_number}\n{self.line}"


class UnknownCommand(MyBaseException):
    def __init__(self, line, line_number):
        self.line_number = line_number + 1
        self.line = line
    
    def what(self):
        return f"Неизвестная команда. Строка: {self.line_number}\n{self.line}"


class UnknownVar(MyBaseException):
    def __init__(self, line, line_number, var_name):
        self.line_number = line_number + 1
        self.line = line
        self.var_name = var_name
    
    def what(self):
        return f"Неизвестная переменная '{self.var_name}'. Строка: {self.line_number}\n{self.line}"

    
class UseUnitiailizeVar(MyBaseException):
    def __init__(self, line, line_number, var_name):
        self.line_number = line_number + 1
        self.line = line
        self.var_name = var_name
    
    def what(self):
        return f"Обращение к неинициализированной переменной '{self.var_name}'. Строка: {self.line_number}\n{self.line}"


class VarAttributeError(MyBaseException):
    def __init__(self, line, line_number, var_name):
        self.line_number = line_number + 1
        self.line = line
        self.var_name = var_name
    
    def what(self):
        return f"Обращение к неизвестному атрибуту переменной '{self.var_name}'. Строка: {self.line_number}\n{self.line}"


class VarTypeError(MyBaseException):
    def __init__(self, line, line_number):
        self.line_number = line_number + 1
        self.line = line
    
    def what(self):
        return f"Ошибка приведения значения переменной к строковому типу. Строка: {self.line_number}\n{self.line}"
                