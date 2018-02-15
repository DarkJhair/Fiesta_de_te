/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package twitterprueba;
import twitter4j.*;
import java.util.List;
import twitter4j.Query;
import twitter4j.QueryResult;
import twitter4j.StatusUpdate;
import twitter4j.Twitter;
import twitter4j.TwitterFactory;
import twitter4j.User;
import twitter4j.Status;
import twitter4j.TwitterException;
import twitter4j.conf.ConfigurationBuilder;

import java.io.*;
import sun.awt.FwDispatcher;

/**
 *
 * @author Jhair
 */
public class TwitterPrueba {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws TwitterException {
        // TODO code application logic here
        ConfigurationBuilder cb = new ConfigurationBuilder();
        
        cb.setDebugEnabled(true);
        cb.setOAuthConsumerKey("CJnaPXYtcKwOBjIb6yAfCw0a7");
        cb.setOAuthConsumerSecret("bblOp5MFJ4BFsIBewBuXmMZiahPo0gXM4HT6Lz1ZZgMHY0lkI0");
        cb.setOAuthAccessToken("3177506198-o5rYWh6c8s1KCpx6eKhZqSwVWceAbfKcaHMTQk6");
        cb.setOAuthAccessTokenSecret("QM7ChjUxyNPJGAntMKnvBs7AxOmoGKarDtnINWFWb6QdZ");
        TwitterFactory tf = new TwitterFactory(cb.build());
        Twitter twitter = tf.getInstance();
        String usuario="jhair001";
        //aqui ponemos el file donde guardamos los tweets
        File file = new File("tweets.txt");
        try {
            FileWriter fw = new FileWriter(file);
         
         Query que= new Query("unitec");
         QueryResult result;
       
        result= twitter.search(que);
        List<Status>statuses=result.getTweets();
        User user = twitter.showUser("Jhair001");
        Status tweet = twitter.showStatus(30);    
        //twitter.sendDirectMessage("jufergom", "Julio es gay, enviado desde java prrrooo, +100 lince para mi");
        
        System.out.println(usuario);
        
            for (Status status : statuses) {
                System.out.println(status.getUser().getScreenName()+"<<<  >>> "+status.getText()+"<<<  >>> "+status.getUser().getTimeZone()
                        +"<<<  >>> "+status.getUser().getName());
                fw.write(status.getUser().getScreenName()+"<<<  >>> "+status.getText()+"<<<  >>> "+status.getUser().getTimeZone()
                        +"<<<  >>> "+status.getUser().getName());
            }
            fw.close();
                //System.out.println(tweet);   
           /* for (int i = 0; i < 5; i++) {
                System.out.println(user.getName()+"<<<  >>> "+user.getScreenName() +"<<<  >>> "+ user.getStatus());
            }*/
     
         
                
        } catch (TwitterException te) {
            System.out.println("Failed to search tweets: " + te.getMessage());
            System.exit(-1);
        }
        catch (IOException e) {
            
        }
        /*
       
         if (args.length < 1) {
            System.out.println("java twitter4j.examples.search.SearchTweets [jhair001]");
            System.exit(-1);
        }
        Twitter twitter = new TwitterFactory().getInstance();
        try {
            Query query = new Query(args[0]);
            QueryResult result;
            do {
                result = twitter.search(query);
                List<Status> tweets = result.getTweets();
                tweets.forEach((tweet) -> {
                    System.out.println("@" + tweet.getUser().getScreenName() + " - " + tweet.getText());
                });
            } while ((query = result.nextQuery()) != null);
            System.exit(0);
        } catch (TwitterException te) {
            System.out.println("Failed to search tweets: " + te.getMessage());
            System.exit(-1);
        }
    */
       
    }    
        
        
    
    
}
