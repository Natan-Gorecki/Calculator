using CalculatorWPF.Models;
using System;
using System.Collections.ObjectModel;
using System.ComponentModel;

namespace CalculatorWPF.Services;

public interface ICalculatorService : INotifyPropertyChanged, IDisposable
{
    string Summary { get; set; }
    string Expression { get; set; }
    ObservableCollection<CalculationEntry> CalculationEntries { get; }
    ObservableCollection<CalculationEntry> MemoryEntries { get; }

    bool PerformCalculation(out double value);
    void AppendToExpression(string number);
}
