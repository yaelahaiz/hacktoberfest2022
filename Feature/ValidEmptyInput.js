
Result Size: 625 x 389
<!DOCTYPE html>
<html>
<head>
<script>
function validateForm() {
  var x = document.forms["myForm"]["fname"].value;
  if (x == "" || x == null) {
    alert("Name must be filled out");
    return false;
  }
}
</script>
</head>
<body>

<h2>JavaScript validation for empty input field</h2>
<p>Try to submit the form without entering any text.</p>

<form name="myForm" action="/action_page.php" onsubmit="return validateForm()" method="post" required>
  Name: <input type="text" name="fname">
  <input type="submit" value="Submit">
</form>

</body>
</html>
