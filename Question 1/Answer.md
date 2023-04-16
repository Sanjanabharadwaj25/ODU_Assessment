##### Intent : Learn the basics of how web applications are built and what technologies could be used for web applications. 
Suppose you were given to build a web application for https://www.boats.com/ from scratch as a startup . Imagine you would be solely responsible to build it’s frontend, backend, design database, setup media storage, deployment, ci/cd automation and everything else. Thus, do some research on your part and write down your response to the following questions. 

The web application mentioned in the question talks about a marketplace for boats where the following features are made available to users
  - View listings of all boats available for sale as a Buyer
  - Create an account as a seller and submit listing
  - Rent a boat for a specific activity(Cruising, watersports, etc)
  - Look at online reviews on boats
  - Latest news in the boat industry
  - Pay for a premium account/listing
  - Other services

##### Assumptions
1. The startup is getting considerable traffic with 1.7 Million total visits and an average visit duration of about 3 minutes ([Source](https://www.similarweb.com/website/boats.com/#overview)) and will need to be scalable
2. Since this is a startup, the team is also assumed to be lean/thin and would factor into the choice of backend and frontend technologies

### Questions
## 1. Which backend framework would you prefer to use and why?


   The following languages/frameworks were adopted for comparison
     1. ExpressJS (JavaScript/TypeScript)
      2. Spring Boot (Java)

#### Comparitive Analysis

|Criteria |ExpressJS (JS/TS)  | Spring Boot | Reasoning
|---	|---	|---	|---	|
|Scalability   	|9/10   	|8/10   	| While both frameworks are highly scalable, ExpressJS has a slight edge due to it's event driven architecture which enables it to handle a higher volume of requests |
|Performance   	|9/10   	|8/10   	| Both frameworks have strong performance, But ExpressJS has a slight advantage due to it's minimalist design and low overheads|
|Security   	|7/10   	|9/10   	| Spring Boot has a more comprehensive security framework and is better suited for applications with a high requirement of security |
|Community   	|9/10   	|10/10   	| Spring Boot has been around for a longer time and enjoys a long standing presence in the Java ecosystem, and hence has a larger community |
|Documentation   	|8/10   	|9/10   	| Spring Boot's documentation is more extensive due to it's long standing presense and larger community |
|Maintenance   	|9/10   	|8/10   	| Spring Boot is harder to maintain due to it's more comprehensive and extensive feature set and larger codebase |

While both of these frameworks have their own advantages, it is clear that *ExpressJS* is more suited for developing this kind of an application. 

## 2. Which frontend framework would you prefer to use and why?

The choice of frontend framework would be *NextJS* that helps with server side rendering and static site generation. Here are some reasons why
  - Since the web application would have thousands of listings for boats, it would also require very good Search Engine Optimisation(SEO) to ensure higher visibilty across customers
  - With the reviews and news components present on the web application, static site generators can also be useful in maintaining these parts of the application
  - The adoption of React has been the highest compared to any other frontend library due to it's very easy learning curve, amazing community and an ecosystem of various extensions/integrations
  - Finding/Hiring talent would be easier since React/NextJS is a widely used technology
  - The optional switching between server-side rendered and client-side rendered pages provide developers with the flexibility to make significant and decisive tradeoffs between performance and seo.  

## 3. Which database would you prefer to use and why?

Since all the data present for the web application is highly relational in nature, an RDBMS would be the right choice of a database here. Out of the available options for an RDBMS(MySql, MSSQL, postgresql), I would choose *PostgreSQL* for it's flexibility, extension support, JSON type support, etc

*Entities*
- Boats
- Users
- Activities
- Categories
- Reviews
- News

*Relationships*
- A User lists their boat for selling
- A User buys a boat 
- A User can partake in activities
- Activities belong to a specific Category
- Boats and activities are reviewed by Users
- Users can view/interact with latest news from the boat community

Here's a minimalistic representation of the database schema

<img width="1427" alt="Screenshot 2023-04-16 at 8 49 56 AM" src="https://user-images.githubusercontent.com/16634631/232264558-5abc59b4-a58f-401a-8924-4b59a43d0178.png">


## 3. What would you use for version control of the codebase ?

I would choose *Git*, a distributed version control system. Git is one of the most popular and easy to use systems available for source code management. As a Git client, I would use Github for it's easy to use interface and support for Github Actions. With an extremely vibrant community and a large ecosystem of Github actions, the developer productivity would definitely be higher with Git.


## 4. Which platform would you prefer for media storages ( eg. storage of product images) ?

There are 2 types of media storage available for varied usecases. 
1. Database Storage(Blob storage in RDBMS)
2. Object storage with solutions like Amazon S3, Google Drive, DropBox, etc. 

For the usecase considered, here are the major requirements for media storage
1. Listing images that are presented to the user on the web application - For this usecase, speed of delivery is of the utmost importance to ensure the user has a productive experience without a lot of wait time. A cloud CDN constructed to serve from an object storage like Amazon S3 would be the ideal choice for this usecase. Databases might not be the right choice considering that the size of these boat images uploaded by the seller could be large. 
2. Profile Images - For this usecase, a database blob storage might be more effecient since the images and inherently users are heavily indexed on `id` and other fields, making access faster. Also, since the profile picture is uploaded on the web application, size of the image can be restricted, thereby ensuring low latency for queries. 


## 4. Where would you deploy your application and which web server would you use and why?

A cloud based solution would be the most optimal solution to deployment since we would also use peripheral services like Object storage, VPNs, etc. Considering cloud based storage, here are the choices of server/deployment technologies I would use

- Backend Service - Hosted on an AWS virtual machine which is proxied by `nginx` and run using `pm2`
- Frontend Service - NextJS application is hosted on Vercel's network. Takes care of CDN based server-side rendering, etc.