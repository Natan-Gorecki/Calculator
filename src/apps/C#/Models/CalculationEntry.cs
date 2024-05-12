using System.Diagnostics.CodeAnalysis;

namespace CalculatorWPF.Models;

public class CalculationEntry
{
    public CalculationEntry()
    {
    }

    [SetsRequiredMembers]
    public CalculationEntry(double value)
        : this(value.ToString(), value)
    {
    }

    [SetsRequiredMembers]
    public CalculationEntry(string summary, double value)
    {
        Summary = summary;
        Value = value;
    }

    public required string Summary { get; init; }
    public required double Value { get; init; }
}
