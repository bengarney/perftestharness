# Introduction #

This page is a temporary holding spot for brainstorming.  This will probaby need to be organized better some day soon.


# Tasks #

Harness Work

  * Gather machine info for recording.  Look at the CPUID instruction.

  * Modify the test harness to run each benchmark as a single process.

Utility Development

  * Fullscreen quad draw - create a utility function for other to use that draws a screen quad as fast as possible.  This quad should suppot a texture, but not require one.  The quad should also support the abilty to execute a pixel shader.

  * Vertex Limiter - the vertex limiter should generate as many degenerate triangles as possible until the frame rate hits 60 hz.  Once that happens, the vertex limiter will return true and return (via some function call) the vertex buffer pointer, number of degenerate triangles and the index buffer.

  * Pixel Shader Limiter - the pixel shader limiter shall do the same as the vertex limiter, except it shall perform the pixel work using the full screen quad limiter to perform this job.

  * Texture Limiter - the texture limiter shall perform the same work as the vertex limiter, except it shall perform the texture work by rendering textures of varying sizes and ammount to a full screen quad.  Users shall be able to specify texture format for the texture limiter.

  * XML utility: So that the xml output is better encapsulated ( to be better defined )

  * Cache purge utility - Allocate a large chunk of memory and step through it, then delete it, so that the cache is cleared before running a test.

GPU Tests

  * Vertex Buffer Size -A single vertex buffer will have an optimal size.  Build a vertex buffer of varying size from small to large and determine, via framerate, what the optimal size is for your hardware.  Start with the vertex limiter so that the program begins at 60 hertz.  The test is over when the fps reaches 30 fps.

  * Vertex Alignment - Start by implmenting the vertex limiter.  Using different permutations of vertex types, increase buffer size until the fps is 30 Hz. Report the total size of the vertex (number of bytes\*sizof(vertexformat)).   The assumption is that vertex types that are aligned to the cache boundaries of the vertex fetching system should be faster than those that are not.  Vertex buffers must be static as to reduce graphics bus bandwidth.

  * Overdraw Performance -  use a full screen quad and a small frambuffer to gather the frame rate at overdraw values of 0,1,2,3,4…x.  Use the fullscreen quad draw to bring the frame rate down to 60.  Once there, continue to add fullsreen quads until the frame rate is at 30 Hz.  Record the fps and number of quads after the 60 hz is achieved.

  * Draw Call Performance Using Semi-sorted Renderstates -Too many draw calls with renderstate changes cause CPU overhead.  X number of draw calls using the same render state, on some drivers, is the same as one draw call.  The drivers, in this case, are batching the render states for you.  Determine how many different render state changes the driver can handle in a loosely sorted list of states.  Create any GPU limiter to bring the frame rate to 60Hz.  Using a single vertex buffer, implement a loop to draw the buffer in increments of 100.  Now write the program so that it changes render states between draw calls.  Change the first render state ever other call and measure the frame rate.  Change the second render state every third call.  Continue this process until the framerate is below 30.

  * Frequency of Updating a Static Vertex Buffer - It has been suggested that some drivers will change a static vertex buffer that is locked more often to a dynamic buffer that utilizes non-local video memory.  Use the vertex limiter to create a scene that executes at 60 Hz.  Create an fill a vertex buffer until the framerate is 30 Hz. Lock the buffer at intervals other than every frame and track the framerate delta.

  * Vertex Shader Control of Flow - Using the shader lab, experiment with different types of vertex shader branches to determine performance.  Chart the differences between:

1)If then else statements with random conditions

1)If then else statements without predictable conditions

2)If then else statements with semi-random conditions (interleave true and false on intervals of 31, 32, and 33.)

3)Loops with random conditions

4)Loops with static conditions

  * Texture Filtering Performance - Using the texture limiter, create an application that is texture bound.  Use a simple shader to test out all types of filtering performance.  Use a DXT1 texture as your test texture.


CPU Tests
  * CPU Stream Count - Hardware prefetching hides the latency of memory fetching for our CPUs.  Hardware prefetching can track more than one "stream" of memory.  Create a struct with at least 32 members in a Structure of Arrays (SOA) format.  Array size should be 4 megs.  In your first test, linearly access memory in the first member.  In the second test, iterate through the first and second member, but only iterate halfway through the entire array.  The assumption is that the CPU can track multiple streams of memory for hardware prefetching.  This test attempts to plot increasing numbers of streams without increasing the total amount of memory streamed.

  * Datatypes and Operators - This test iterates through a series of multiply, divide, minus, and plus operators for different datatypes.  To reduce unfair compilation optimizations, perform these tests on series of linear arrays populated with random data of the appropriate types.

  * Random vs. linear memory access vs. strided access - Memory latency is hidden by hareware prefetching.  This test measures different access patterns in memory.  Memory traversals on integer datatypes will be random, linear, and strided access.  (note: this test is alreay implmented)

  * Sulti-thread linear access - perform linear access on an array using a linear memory access pattern.  Collect data for [1..64] threads.

  * Single vs. multi-thread random access  - perform the same test as the above test replacing linear access with random access.

  * Float to Int/ Int to Float Conversions [be completed](to.md)