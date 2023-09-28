<p align="center">
	<img src="https://github.com/maxencebonamy/maxencebonamy/blob/main/assets/Sand_Box.png" width="100%" alt="Sand Box">
</p>

https://github.com/maxencebonamy/Sand-Box/assets/66129931/98f83fe8-437f-4502-9f61-f1b0365b798f
https://github.com/maxencebonamy/maxencebonamy/blob/main/assets/sand_box.mp4

<br>

<p align="center">
	<img src="https://github.com/maxencebonamy/maxencebonamy/blob/main/assets/1_Description.png" width="100%" alt="Description">
</p>

This software is a physical simulation. You can arrange different physical elements anywhere in the window, and they will evolve with each other according to the laws of physics.

<img src="https://github.com/maxencebonamy/Sand-Box/blob/main/assets/void.png" alt="air" height="24px" align="top"> **Air:** the basic element, used above all to "clear" the screen if you've placed too many elements. Be careful: if you place air in water, the air will obviously rise to the surface.

<img src="https://github.com/maxencebonamy/Sand-Box/blob/main/assets/sand.png" alt="sand" height="24px" align="top"> **Sand:** evolves simply like powder, so is subject to gravity and forms hills.

<img src="https://github.com/maxencebonamy/Sand-Box/blob/main/assets/water.png" alt="water" height="24px" align="top"> **Water:** evolves simply like a liquid, so is also subject to gravity, but spreads wherever possible.

<img src="https://github.com/maxencebonamy/Sand-Box/blob/main/assets/steam.png" alt="steam" height="24px" align="top"> **Steam:** evolves simply like a gas, but rises as high as possible because steam is lighter than air. Steam can return to its liquid state and turn back into water after a while, which is similar to rain.

<img src="https://github.com/maxencebonamy/Sand-Box/blob/main/assets/wood.png" alt="wood" height="24px" align="top"> **Wood:** here, the wood doesn't fall, which may seem odd, but you have to imagine that it's fixed in height. The wood burns and the fire spreads relatively quickly over it.

<img src="https://github.com/maxencebonamy/Sand-Box/blob/main/assets/fire.png" alt="fire" height="24px" align="top"> **Fire:** heats or even burns an element. Placed next to wood, it ignites the latter. Placed near snow or ice, it will transform it into water, and will also transform the latter into steam.

<img src="https://github.com/maxencebonamy/Sand-Box/blob/main/assets/ash.png" alt="ash" height="24px" align="top"> **Ash:** when wood burns, it turns to ash, which falls like sand, thus acting like powder.

<img src="https://github.com/maxencebonamy/Sand-Box/blob/main/assets/stone.png" alt="stone" height="24px" align="top"> **Stone:** like wood, it doesn't fall, and you have to imagine that it's "fixed". There's nothing special about stone, except that it doesn't burn.

<img src="https://github.com/maxencebonamy/Sand-Box/blob/main/assets/acid.png" alt="acid" height="24px" align="top"> **Acid:** dissolves any element, such as stone. Caution: when acid touches water, it dissolves.

<img src="https://github.com/maxencebonamy/Sand-Box/blob/main/assets/snow.png" alt="snow" height="24px" align="top"> **Snow:** acts like a classic powder, like sand or ashes. Beware, however, that snow sometimes transforms into water after a certain time, as the temperature of the simulation is considered to be room temperature.

<img src="https://github.com/maxencebonamy/Sand-Box/blob/main/assets/ice.png" alt="ice" height="24px" align="top"> **Ice:** like wood or stone, ice is not subject to gravity. And like snow, it melts after a certain time, turning into water.

<br>

<p align="center">
	<img src="https://github.com/maxencebonamy/maxencebonamy/blob/main/assets/2_Get_Started.png" width="100%" alt="Get Started">
</p>

### Launch the software:

1. Click on the <a href="https://github.com/maxencebonamy/Sand-Box/releases" target="_blank">Releases</a> button on the right and select the **latest version**.
2. Download the **.zip** archive and extract the files.
3. Run the **.exe** executable.

### Compile:

> [!NOTE]
> *Prerequisites:*
> - [x] *Git must be installed on your computer. If not, <a href="https://git-scm.com/downloads" target="_blank">click here.</a>*
> - [x] *Xmake must be installed on your computer, if not, <a href="https://xmake.io/#/getting_started?id=installation" target="_blank">click here.</a>*
<br>

1. **Clone** the repository on your computer. To do this, open a terminal in the folder of your choice and run the following command:
```
git clone https://github.com/maxencebonamy/Sand-Box
```

2. **Navigate** inside the folder you've just cloned with the following command:
```
cd Sand-Box
```

3. **Compile** the project with the following command:
```
xmake
```

4. **Run** the executable with this command:
```
xmake run
```

<br>

<p align="center">
	<img src="https://github.com/maxencebonamy/maxencebonamy/blob/main/assets/3_Features.png" width="100%" alt="Features">
</p>

### Actions you can perform in the software:
- Hold down the left click and move your mouse to place elements on the window.
- Right-click to show or hide the selection bar for the current element.
- If the element selection bar is displayed, simply left-click on an element to select it.
