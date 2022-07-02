extends Node2D

var screensize

# Called when the node enters the scene tree for the first time.
func _ready():
	hide()
	screensize = get_viewport_rect().size

func _process(delta):
	var button = $StartButton
	var girl = $"2DGirl"
	button.connect("pressed", girl, "_on_StartButton_pressed")
