using System;
using System.Windows.Input;

namespace PC_App.Commands
{
    class Command : ICommand
    {
        Action _execute;

        public Command(Action executeMethod)
        {
            _execute = executeMethod;
        }

        public void Execute(object parameter)
        {
            if (_execute != null)
            {
                _execute();
            }
        }

        public bool CanExecute(object parameter)
        {
            return true;
        }

        public event EventHandler CanExecuteChanged;
    }
}