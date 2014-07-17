
local spine = require "spine-corona.spine"

--local name = "goblins"
local name = "spineboy"

local json = spine.SkeletonJson.new()
json.scale = 1
local skeletonData = json:readSkeletonDataFile("data/" .. name .. "/" .. name .. ".json")
local walkAnimation = skeletonData:findAnimation("walk")

local skeleton = spine.Skeleton.new(skeletonData)
function skeleton:createImage (attachment)
	-- Customize where images are loaded.
	return display.newImage("data/" .. name .. "/" .. attachment.name .. ".png")
end
skeleton.group.x = 150
skeleton.group.y = 325
skeleton.flipX = false
skeleton.flipY = false
skeleton.debug = true -- Omit or set to false to not draw debug lines on top of the images.
if name == "goblins" then skeleton:setSkin("goblingirl") end
skeleton:setToBindPose()

local lastTime = 0
local animationTime = 0
Runtime:addEventListener("enterFrame", function (event)
	-- Compute time in seconds since last frame.
	local currentTime = event.time / 1000
	local delta = currentTime - lastTime
	lastTime = currentTime

	-- Accumulate time and pose skeleton using animation.
	animationTime = animationTime + delta
	walkAnimation:apply(skeleton, animationTime, true)
	skeleton:updateWorldTransform()
end)

