<!DOCTYPE html>
<html>
<title>CSI-DBIT</title>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<link rel="stylesheet" href="styles.css">
<link rel="stylesheet"
	href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
<link rel="icon" href="dbit.png" type="image/png">
<style>
body, h1, h2, h3, h4, h5, h6 {
	font-family: "Courier New", sans-serif
}

.w3-bar, h1 {
	font-family: "Courier New", sans-serif
}

body {
	font-size: 100%;
}

.division {
	border-radius: 5px;
	background-color: #f2f2f2;
	padding: 20px;
	width: 100%;
	margin-left: auto;
	margin-right: auto;
}

* {
	box-sizing: border-box
}

.mySlides {
	display: none
}

/* Slideshow container */
.slideshow-container {
	position: relative;
	margin: auto;
}

/* The dots/bullets/indicators */
.dot {
	height: 13px;
	width: 13px;
	margin: 0 2px;
	background-color: #bbb;
	border-radius: 50%;
	display: inline-block;
	transition: background-color 0.6s ease;
}

.active {
	background-color: #717171;
}

/* Fading animation */
.fade {
	-webkit-animation-name: fade;
	-webkit-animation-duration: 1.5s;
	animation-name: fade;
	animation-duration: 1.5s;
}

@
-webkit-keyframes fade {
	from {opacity: .4
}

to {
	opacity: 1
}

}
@
keyframes fade {
	from {opacity: .4
}

to {
	opacity: 1
}

}

/* On smaller screens, decrease text size */
@media only screen and (max-width: 300px) {
	.text {
		font-size: 11px
	}
}
</style>
<body>

	<!-- Navbar -->
	<div class="w3-top">
		<div class="w3-bar w3-teal w3-card-2 w3-left-align w3-large">
			<a
				class="w3-bar-item w3-button w3-hide-medium w3-hide-large w3-right w3-padding-large w3-hover-white w3-large w3-teal"
				href="javascript:void(0);" onclick="myFunction()"
				title="Toggle Navigation Menu"><i class="fa fa-bars"></i></a> <a
				href="index.php"
				class="w3-bar-item w3-button w3-padding-large w3-white">Home</a> <a
				href="about.html"
				class="w3-bar-item w3-button w3-hide-small w3-padding-large w3-hover-white">About</a>
			<a href="csiwork.php"
				class="w3-bar-item w3-button w3-hide-small w3-padding-large w3-hover-white">CSI
				Work</a> <a href="committee.html"
				class="w3-bar-item w3-button w3-hide-small w3-padding-large w3-hover-white">Core
				Committee</a> <a href="contact.html"
				class="w3-bar-item w3-button w3-hide-small w3-padding-large w3-hover-white">Contact</a>
		</div>

		<!-- Navbar on small screens -->
		<div id="navDemo"
			class="w3-bar-block w3-white w3-hide w3-hide-large w3-hide-medium w3-large">
			<a href="about.html" class="w3-bar-item w3-button w3-padding-large">About</a>
			<a href="csiwork.php" class="w3-bar-item w3-button w3-padding-large">CSI
				Work</a> <a href="committee.html"
				class="w3-bar-item w3-button w3-padding-large">Core Committee</a> <a
				href="contact.html" class="w3-bar-item w3-button w3-padding-large">Contact</a>
		</div>
	</div>

	<!-- Header -->
	<div class="w3-content" style="max-width: 2000px; margin-top: 46px">
		<?php
   include "database.php";
   
   $sql = 'select * from slides';
   
   $retval = mysql_query( $sql, $conn );
   
   if(! $retval ) {
      die('Could not get data: ' . mysql_error());
   }
   
   while($row = mysql_fetch_assoc($retval)) 
   {
  	echo "<div class='mySlides fade w3-display-container w3-center'>";
  	echo "<img src='" . $row['name'] . "'style='width: 100%'><div
				class='w3-display-bottommiddle w3-container w3-text-white w3-padding-32 w3-hide-small'>
			</div>";
  	echo "</div>";
   }
   mysql_free_result($retval);
   
   mysql_close($conn);   
?>
	</div>
	<br>
	<center>
		<div class="w3-container" id="newsfeed">
			<h1 class="w3-xxxlarge w3-text-teal">< news_feed /></h1>
		</div>
	</center>
	<!-- Second Grid -->
	<div class="division">
		<?php
   include 'database.php';
   
   $sql = 'select * from newsfeed';
   
   $retval = mysql_query( $sql, $conn );
   
   if(! $retval ) {
      die('Could not get data: ' . mysql_error());
   }
   
   while($row = mysql_fetch_assoc($retval)) {
      echo "<a href='".$row["link"]."'><p>". $row["name"]. "</a>    <sub>".$row["date"] . "</sub></p><br>"; 
	}
   mysql_free_result($retval);
   
   mysql_close($conn);   
?>
	</div>
	<a href="login.php"><p align="right">Login</p></a>
	<!-- Footer -->
	<footer class="w3-container w3-padding-64 w3-center w3-opacity">
		<p>Developed by CSI DBIT</p>
	</footer>

	<script>
		// Used to toggle the menu on small screens when clicking on the menu button
		function myFunction() {
			var x = document.getElementById("navDemo");
			if (x.className.indexOf("w3-show") == -1) {
				x.className += " w3-show";
			} else {
				x.className = x.className.replace(" w3-show", "");
			}
		}
		var myIndex = 0;
		carousel();

		function carousel() {
			var i;
			var x = document.getElementsByClassName("mySlides");
			for (i = 0; i < x.length; i++) {
				x[i].style.display = "none";
			}
			myIndex++;
			if (myIndex > x.length) {
				myIndex = 1
			}
			x[myIndex - 1].style.display = "block";
			setTimeout(carousel, 4000);
		}
	</script>

</body>
</html>
