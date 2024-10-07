<?php
$n = 10;

if ($n == 0 || $n == 1) {
    $result = $n;
} else {
    $fib = array(0, 1);

    for ($i = 2; $i <= $n; $i++) {
        $fib[$i] = $fib[$i - 1] + $fib[$i - 2];
    }

    $result = $fib[$n];
}

echo "Fibonacci of $n is: $result";
?>
