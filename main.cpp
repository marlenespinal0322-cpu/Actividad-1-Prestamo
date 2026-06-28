using System;

// Nombre: Juan Erminio Perez D. Matrícula: 25-SSON-2-001
// Marlen Crismel Espinal A. Matrícula: 25-SSON-2-002

//  - Tarea 1
// Archivo: Tarea1_Prestamo.cs
// Profesor: Gamalier Reyes del Carmen
// Actividad: Flujo de Control (parte 1)
// Calcula la cuota mensual de un préstamo usando monto, tasa anual y tiempo en meses.
// Fórmula de la cuota de préstamo:
// cuota = monto * tasaMensual / (1 - (1 + tasaMensual)^-meses)
// donde tasaMensual = (tasaAnual / 100) / 12
// Esta fórmula calcula una cuota fija mensual que cubre intereses y capital.

Console.WriteLine("==================================================");
Console.WriteLine("       CÁLCULO DE CUOTA DE PRÉSTAMO               ");
Console.WriteLine("==================================================");

decimal monto = LeerDecimal("Ingrese el monto del préstamo (RD$): ");
decimal tasaAnual = LeerDecimal("Ingrese la tasa de interés anual (%): ");
int meses = LeerEntero("Ingrese el tiempo a pagar (en meses): ");

if (meses <= 0)
{
    Console.WriteLine("El tiempo debe ser mayor que cero.");
}
else
{
    decimal tasaMensual = (tasaAnual / 100m) / 12m;
    decimal cuota = tasaMensual == 0
        ? monto / meses
        : monto * tasaMensual / (1 - (decimal)Math.Pow((double)(1 + tasaMensual), -meses));

    Console.WriteLine("\n==================================================");
    Console.WriteLine("               RESULTADOS DEL PRÉSTAMO            ");
    Console.WriteLine("==================================================");
    Console.WriteLine($"Monto del préstamo : RD$ {monto:N2}");
    Console.WriteLine($"Tasa de interés     : {tasaAnual}% anual");
    Console.WriteLine($"Tiempo a pagar      : {meses} meses");
    Console.WriteLine($"Cuota fija mensual  : RD$ {cuota:N2}");
    Console.WriteLine("==================================================");
}

Console.WriteLine("\nPresione cualquier tecla para salir...");
Console.ReadKey();

static decimal LeerDecimal(string mensaje)
{
    decimal valor;
    while (true)
    {
        Console.Write(mensaje);
        string? entrada = Console.ReadLine();

        if (entrada != null && decimal.TryParse(entrada.Trim(), out valor) && valor >= 0)
        {
            return valor;
        }

        Console.WriteLine("Entrada inválida. Por favor, ingrese un número válido.");
    }
}

static int LeerEntero(string mensaje)
{
    int valor;
    while (true)
    {
        Console.Write(mensaje);
        string? entrada = Console.ReadLine();

        if (entrada != null && int.TryParse(entrada.Trim(), out valor) && valor > 0)
        {
            return valor;
        }

        Console.WriteLine("Entrada inválida. Por favor, ingrese un número entero positivo.");
    }
}
