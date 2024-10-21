<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Retrieve values from the form
    $name = htmlspecialchars($_POST['name']);
    $age = (int)$_POST['age'];

    // Determine if the person is a minor or major
    if ($age < 18) {
        echo "$name is minor";
    } else {
        echo "$name is major";
    }
} else {
    echo "Invalid request method.";
}
?>
