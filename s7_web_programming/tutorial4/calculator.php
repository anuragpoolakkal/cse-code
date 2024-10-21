<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Simple Calculator</title>
</head>
<body>

<h2>Simple Calculator</h2>
<form action="" method="GET">
    <label for="num1">Number 1:</label>
    <input type="text" id="num1" name="num1" required>
    <br><br>
    <label for="num2">Number 2:</label>
    <input type="text" id="num2" name="num2" required>
    <br><br>
    <input type="submit" value="Calculate">
</form>

<?php
if ($_SERVER["REQUEST_METHOD"] == "GET" && isset($_GET['num1']) && isset($_GET['num2'])) {
    // Collect the form data
    $num1 = $_GET['num1'];
    $num2 = $_GET['num2'];

    if (is_numeric($num1) && is_numeric($num2)) {
        // Convert inputs to float
        $num1 = floatval($num1);
        $num2 = floatval($num2);

        $sum = $num1 + $num2;
        $difference = $num1 - $num2;
        $product = $num1 * $num2;

        // Display the results
        echo "<h3>Results:</h3>";
        echo "Sum: " . $sum . "<br>";
        echo "Difference: " . $difference . "<br>";
        echo "Product: " . $product . "<br>";
    } else {
        echo "<h3>Please enter valid numeric values.</h3>";
    }
}
?>

</body>
</html>
