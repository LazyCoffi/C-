extends Area2D


# Declare member variables here. Examples:
# var a = 2
# var b = "text"

var vis = false

# Called when the node enters the scene tree for the first time.
func _ready():
	pass # Replace with function body.

func _on_StartButton_pressed():
	if vis:
		self.show()
	else:
		self.hide()
	
	vis = not vis
