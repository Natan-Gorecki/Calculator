using CalculatorCLI;
using CalculatorWPF.Services;
using CommunityToolkit.Mvvm.DependencyInjection;
using Microsoft.Extensions.DependencyInjection;
using System.Windows;

namespace CalculatorWPF;

public partial class App : Application
{
    public static Ioc Ioc { get; set; }

    static App()
    {
        Ioc = Ioc.Default;
        Ioc.ConfigureServices(new ServiceCollection()
            .AddSingleton<ICalculator, Calculator>()
            .AddSingleton<ICalculatorService, CalculatorService>()
            .BuildServiceProvider());
    }
}
