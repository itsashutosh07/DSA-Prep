
### Some Important Moves:
##### Right trigger: 
#right-trigger 
1. With right hand, rotate the the *right face clock-wise*.
2. Rotate the *top clock-wise*.
3. With right hand, rotate the the *right face counter clock-wise*.
##### Left trigger: 
#left-trigger 
1. With right hand, rotate the the *right face clock-wise*.
2. Rotate the *top clock-wise*.
3. With right hand, rotate the the *right face counter clock-wise*.

##### Righty algorithm
\[#righty-algo = #right-trigger + top counter clock-wise]
1. Rotate the **right face clock-wise**.
2. Rotate the **top clock-wise**.
3. Rotate the **right face counter clock-wise**.
4. Rotate the **top counter clock-wise**.

> Notation: **R U R' U'**  
> (= #right-trigger + top Counter-ClockWise)

##### Lefty algorithm
\[ #lefty-algo = #left-trigger + top clock-wise]
1. Rotate the **left face counter clock-wise**.
2. Rotate the **top counter clock-wise**.
3. Rotate the **left face clock-wise**.
4. Rotate the **top clock-wise**.

> Notation: **L' U' L U**  
> (= #left-trigger + top ClockWise)

---
## Step-1: Make a White '+' sign
1. Face the yellow side to the top
2. Form a daisy 
	1. [yellow in between] + [white at the 4 edges]
3. Match and rotate 180-degree
	1. Match the the white-edge + other-color to the matching other-color center piece and rotate the matched piece a 180-degree

---
## Step-2: Complete the 1st layer
1. Find and fix the white corner pieces.
	1. Find a white pieces on the top layer that is facing outward [the yellow center piece facing top]
	2. find the color adjacent to the white piece and find its matching center piece.
		1. If the piece falls to the right of the matched center, perform a #left-trigger.
		2. If the piece falls to the right of the matched center, perform a #right-trigger.
**Edge Cases**: If there are no white piece remaining on the top-layer that are facing outward, they can be only in two spots [the yellow center piece facing top]
###### Edge Case-1:Outward facing white sticker on the bottom layer
- Find the corner and check which side the white sticker is on.
- If white is on the **right** → perform #right-trigger **once**.
- If white is on the **left** → perform #left-trigger **once**.
- This moves the corner to the top layer facing outward — then solve normally (Step-2).
###### Edge Case-2:
1. Turn the **top face** until the top white sticker sits **directly above a non-white sticker** on the bottom (not above another white).
2. Check which side the white sticker is on:
   - If on the **right** → perform #right-trigger **twice**.
   - If on the **left** → perform #left-trigger **twice**.
3. The corner is now on the top layer facing outward — match its side color diagonally to its center and perform the appropriate trigger.

---
## Step-3: Complete the 2nd layer

*Goal*: place all **middle-layer edge pieces**. When done, the **first two layers** are fully solved.

1. Search the **top layer** for edge pieces with **no yellow** on them.
2. Turn the top until the **side-facing color** of that edge matches its center — you should see an **upside-down T**.
3. Look at the color on the **top face** of that edge piece:
   4. If it matches the **right** center:
      1. Pull the **top face towards you once** → **U**.
      2. Perform #right-trigger.
   5. If it matches the **left** center:
      1. Pull the **top face towards you once with left index** → **U'** (from the right-hand grip, this is one turn the other way).
      2. Perform #left-trigger.
6. Inserting an edge **displaces a white corner** to the top — fix it exactly like Step-2:
   7. Find the displaced white corner on the top layer.
   8. Diagonally match its side color to its center.
   9. Use #left-trigger or #right-trigger as needed.
10. Repeat until all 4 middle edges are in place.

###### Edge Case: No yellow-free edges on top, but middle layer still wrong

- A wrong edge is stuck in the middle layer.
- Hold it on the **right** → perform #right-trigger to **kick it out** to the top.
- Hold it on the **left** → perform #left-trigger to **kick it out** to the top.
- Fix the displaced white corner (Step-2 method).
- The kicked-out edge is now on top with no yellow — insert it normally using the steps above.

> ⚠️ From here on, if you hit a case not covered below, the cube may be in an **unsolvable state** (twisted/reinserted pieces). See [Video-2 description](https://www.youtube.com/watch?v=PW2J8IblczM) — you may need to carefully disassemble and reassemble.

---
## Step-4: Make a Yellow Cross
###### Case-1: Line on top
1. Make line horizontal
2. Rotate front CW.
3. Perform righty-algo ( #right-trigger + top-CCW ).
4. Rotate front back CCW.
###### Case-2: Hook on top
1. Make the top hook face top left (like a mirror image of an L -> \_| )
2. Rotate front CW.
3. 2 x Perform righty-algo ( #right-trigger + top-CCW ).
4. Rotate front back CCW.
###### Case-3: Dot on top
1. Same as *Case-1* -> this brings you to *Case-2* -> Solve for *Case-2*.

---
## Step-5: Match the Yellow Cross w/ center pieces
1. #Sune — track the **pair** (2 connected pieces):
- 2 pieces top + away + down + away + top + back^2
2. Put the pair in the **top layer**.
3. Take it **out** of its slot and **realign the white side**.
4. Put the pair in the **back**.
5. Bring its slot to the **top layer**.
6. **Reinsert** the pair into its slot.
7. **Fix the white side** again.
> Notation: **R U R' U R U2 R'**
8. Turn the top layer and align as many yellow edges to their centers as you can.
	- If **all 4 match** → skip to Step-6.
###### Case-1: Matching edges are **across** from each other
- Hold yellow on top with line vertical like an I.
- Perform **1 x #Sune**.
- Realign the top — you should now have **2 adjacent** matching edges.

###### Case-2: Matching edges are **adjacent**
- Hold the two matched edges at **back** and **right**.
- Perform **1 x #Sune**.
- Realign the top — all 4 edges should match their centers.

---
## Step-6: Fix the Top Corners [Position]
1. #nicklas : 2 pair algo
	1. Right - up + back
	2. Left - up + back
	3. Bring back right pair (1 step)
	4. Bring back left pair (2step)
###### Case-1: No aligned corners
1. Perform **1 x #Niklas** from any angle.
2. Realign the edges on top.
3. You should now have **1 corner** in the correct spot → go to Case-2.
###### Case-2: 1 aligned corners
1. 1. Hold that correct corner at **front-left**.
2. Perform 1 #nicklas 
3. Realign the edges.
	1. You would either have all corners in correct spot
	2. Else: Perform 1 #nicklas again. This would align all your corners perfectly.

---
## Step-7: Orient the Top Corners [Final Step]
1. **Flip the cube upside-down** — **white on top**, **yellow on bottom**.
2. Hold the cube so an **unsolved corner** is at **front-right-bottom**.
3. Perform #righty-algo repeatedly until that corner shows **yellow on the bottom face**:
   - Usually **1–6** repetitions.
4. **Do not rotate the whole cube.**
5. Turn only the **bottom layer (D)** to bring the next unsolved corner to **front-right-bottom**.
6. Repeat #righty-algo until that corner is oriented.
7. Skip corners that are already solved when turning the bottom layer.
8. When all 4 corners are oriented, realign the bottom layer.

**The cube is solved.**


---

### References:

**Video-1** (_till solving 2nd layer_): https://www.youtube.com/watch?v=R-R0KrXvWbc&t=887s

**Video-2** (_2nd layer onwards_): https://www.youtube.com/watch?v=PW2J8IblczM&t=653s






